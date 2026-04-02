application.yml 주석을 확인하여 실행 환경에 맞는 경로 및 주소로 세팅해야한다.

application-private.yml 포맷은 다음과 같다.
카카오 디벨로퍼에서 리다이렉트 경로 등록 후 사용해야한다.
kakao:
  api_key: ""
  login_redirect_uri: "http://  :8080/memberIndex"
  logout_redirect_uri: "http://  :8080"
