# 머신러닝 교과서 with 파이썬, 사이킷런, 텐서플로

## CH1. 컴퓨터는 데이터에서 배운다.
 ### 1.1. 머신러닝의 세 가지 종류
  #### a. 지도학습(supervied learning) : 레이블(rabel)된 훈련 데이터에서 모델을 학습하여 본 적 없는 미래 데이터에 대해 예측
   #### - 분류(classfication) : 클래스 레이블 예측, 이진 분류(binary classification), 결정 경계(decision boundary)
   #### - 회귀(regression) : 연속적인 출력값 예측, 예측변수(X)와 반응변수(Y), 선형 회귀(linear regression)
  #### b. 강화학습(reinforcement) : 환경과 상호 작용하여 에이전트의 성능을 향상, 보상 신호
  #### c. 비지도학습(unsupervised) : 레이블되지 않거나 구조를 알 수 없는 데이터에서 숨겨진 구조 발견
   #### - 군집(clustering) : 서브그룹 찾기
   #### - 차원축소(dimensionality reduction) : 저장공간 및 계산성능의 확보, noise 데이터 제거
  ++준지도학습(semi-supervised) : 레이블된 데이터셋과 레이블이 없는 데이터셋 모두 사용
  ++자기지도학습(self-supervised) : 입력이 타깃이 되는 지도 학습의 특별한 경우/결과값을 재사용 (ex.오토인코더)


  ### 1.2. 기본 용어와 표기법
    a. 행렬과 벡터 : 행(rows), 열(columns)&특성(features)
    b. 머신러닝 용어
      - 훈련샘플 : observation, record, instance, example
      - 훈련 : fitting, parameter estimation
      - 특성(x) : predictor variable, attribute, covariate
      - 타깃(y) : outcome, output, dependent variable, label, ground truth
      - 손실 함수(loss function) : equal to 비용함수(cost function)

  ### 1.3. 머신러닝의 작업흐름
      a. 전처리 : 데이터 형태 갖추기
      b. 예측모델 훈련과 선택
      c. 모델 평가 및 새로운 데이터 샘플로 예측



