# HW1

## 1. HTTP의 정의
  HTTP는 Hypertext Transfer Protocol의 약자로, 이름에서 알 수 있듯이 처음엔 하이퍼텍스트 문서(링크를 통해 서로 다른 문서들을 연결한 문서)를 주고받기 위해 설계된 프로토콜이다. 그래서 최초의 HTTP 버전은 오직 HTML 문서만 주고 받을 수 있었다.
    
   일반적으로 HTTP는 TCP/IP 프로토콜 위에서 동작하는데, 사실 굳이 TCP가 아니어도 된다. 엄밀히 말해 HTTP는 TCP 뿐만 아니라 “reliable”한 프로토콜이면 무엇이든지 상관없다. 실제로 HTTP/3는 UDP를 기반으로 동작하는 QUIC 프로토콜을 기반으로 동작한다.

## 2. HTTP의 역사
  1989년에 Tim Berners-Lee 선생님을 필두로 CERN 기관의 연구자들이 개발하였다. 연구원이다 보니 논문을 읽을 일이 잦았는데, 논문이 단순한 텍스트로 되어 있어 논문에 첨부된 참고 문헌을 일일이 찾아 읽는 것이 번거롭다는 문제가 있었다. 이러한 문제를 해결하기 위해 문서를 링크로 연결할 수 있는 HTML 이라는 문서 양식을 개발하였고 네트워크를 통해 이 HTML을 주고 받을 수 있도록 고안한 프로토콜이 바로 HTTP 다. 여담으로, 하이퍼 텍스트라는 개념은 1960년대 부터 있었지만 당시에는 기술의 한계로 이를 구현할 수 없었고 80년대에 인터넷이 발전하면서 비로소 이를 구현할 수 있게 되었다고 한다.
  ### HTTP 0.9 - The one line protocol
      1991년에 나온 최초의 HTTP 명세로, 0.9라는 버전 명은 원래부터 있었던 것은 아니고 이후에 붙여진 것이다. TCP/IP 위에서 동작하고 기본 포트는 80번을 사용하는, GET 요청만 사용할 수 있는 아주 단순한 프로토콜로서, 클라이언트가 서버에 요청하면 서버는 HTML 형식의 메시지를 응답한 뒤 연결을 종료하는 형태로 동작한다고 명시했다.

      HTTP/0.9의 요청 형식은 아래와 같이 GET 자원경로↵ 뿐이었으며, 이때 ↵는 캐리지 리턴(optional)과 라인 피드를 나타낸다:

      GET /page.html↵

      또한 요청은 idempotent(즉, 동일한 요청에 대해 항상 동일한 응답을 리턴)한 특성을 가지며, 연결이 종료된 이후에 서버는 요청에 관한 어떠한 정보도 저장하지 말 것을 명시하고 있다. 이것이 바로 HTTP가 “stateless”한 프로토콜이라 불리는 이유다. 그리고 심지어 0.9버전에선 HTTP 헤더조차 존재하지 않았다.



