import dlib             # 얼굴인식
import cv2 as cv        # 영상처리
import numpy as np      # 좌표계산
import time             # 시간계산

def test():
    detector = dlib.get_frontal_face_detector()     #얼굴 인식기
 
    predictor = dlib.shape_predictor('C:\shape_predictor_68_face_landmarks.dat')    # 얼굴 부위별로 68개의 점을 찍어주는 모델

    cap = cv.VideoCapture(0)        # 비디오 캡쳐 객체 생성

    index = list(range(0, 68))      # 68개의 점 접근을 위한 리스트화

    faceDetected = False            # 얼굴 판별 여부 확인 변수
    timeRecord = False
    turnHead = False            # 고개 돌리기 판별을 위한 변수

    while True:
        ret, frame = cap.read()     # 비디오의 한 프레임씩 읽음/ 제대로 읽을 시 ret 값 True, 실패시 False
    
        faces = detector(frame, 1)  # dlib를 통해 얼굴 인식

        for face in faces:          # 화면에 검출되는 얼굴만큼 반복
                                
            shape = predictor(frame, face)  # 인식된 얼굴에 68개의 점을 부위별로 지정

            cv.rectangle(frame, (face.left(), face.top()), (face.right(), face.bottom()), (0, 255, 0), 3)
            # 인식된 얼굴을 사각형으로 표시(이미지명, 4각, 색깔, 선 두께)

            point = []              # 각 점의 좌표저장을 위한 list생성

            for p in range(0,68):
                x = shape.part(p).x     # p번째 점의 x 좌표 저장
                y = shape.part(p).y     # p번째 점의 y 좌표 저장
                point.append([x,y])     # list에 점의 좌표 저장

            point = np.array(point)     # list의 행렬화

            for i,pos in enumerate(point[index]):   # i에 순서넣어주고, pos에는 해당 순서에 맞는 좌표 할당
                dot = (pos[0], pos[1])              # dot 변수에 각 점의 위치 할당
                cv.circle(frame, dot, 1, (0, 255, 0), -1)   # 이미지, 좌표, 반지름 , 색상, 색상채움)

            faceDetected = True

        # 2명 이상

        if len(faces) >= 2:
            cv.putText(frame, "Too many examinee", (0, 30), cv.FONT_HERSHEY_SIMPLEX, 1,(0, 0, 255), 2)
            cv.imshow("examinee screen", frame)
            cv.imwrite("C:/20142140/2person.png", frame)
            print("capture")
            break
            
        cv.imshow('Cam Screen', frame)                # 결과 출력 (화면출력창 이름, 영상이미지)

        key = cv.waitKey(1)         # 전달인자: key 입력 대기 시간(단위: ms)

        if key == 27:               # ESC키
            cv.putText(frame, "End of the exam", (0, 30), cv.FONT_HERSHEY_SIMPLEX, 1,(0, 0, 255), 2)
            # 이미지명, 입력 문구, 위치, 글자 폰트, 글자 간격, 글자 색상, 글자 두께
            cv.imshow('20142140', frame)
            break

        if faceDetected:            # 얼굴 탐지 하면
            faceSize = (point[15][0]-point[1][0] + point[14][0]-point[2][0])/2          # 광대 끝과 끝을 이용하여 계산
            leftFaceSize = (point[29][0]-point[1][0] + point[30][0]-point[2][0])/2      # 코와 광대 끝을 이용하여 계산
            rightFaceSize = (point[15][0]-point[29][0] + point[14][0]-point[30][0])/2
        
            if leftFaceSize < 0.3 * faceSize or rightFaceSize < 0.3 * faceSize:         # 얼굴의 비율을 기준으로 고개 돌린 것을 판별
                if not timeRecord:
                    start = time.time()
                turnHead = True
                timeRecord = True
            else :                                                                      # 매번 계산하지않으면 잠깐 고개돌리기만 해도 부정행위로 간주됨 
                turnHead = False
                timeRecord = False

            if turnHead:
                cv.putText(frame, "Don't turn your head", (face.left(), int(face.top() - (face.bottom() - face.top())/10)), cv.FONT_HERSHEY_PLAIN, 1,(0, 0, 255), 1)    # 고개 돌리면 문구 추가하여 경고
                cv.rectangle(frame, (face.left(), face.top()), (face.right(), face.bottom()), (0, 0, 255), 3)                                                           # 빨간색으로 경고 표시
                cv.imshow('cheating detected', frame)
                if timeRecord:              # 부정 행위 시간이 기록되면
                    now = time.time()
                    if now - start > 5:     # 5초이상 지속시
                    
                        #cv.imwrite("C:/20142140/" + time.strftime('%H시%M분%S초') + ".png", frame)                # 이거 왜 저장안되는지 이해가 안됨..
                        cv.imwrite("C:/20142140/" + str(now)+".png", frame)
                        timeRecord = False  # 무한 캡쳐 방지
                        turnHead = False
                        print("capture")
        
    cap.release()

    
