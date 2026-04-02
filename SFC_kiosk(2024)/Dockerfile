FROM openjdk:17-jdk-slim

WORKDIR /app

# Gradle wrapper와 의존성 파일들 먼저 복사
COPY gradlew .
COPY gradle gradle
COPY build.gradle .
COPY settings.gradle .

# 실행 권한 부여
RUN chmod +x gradlew

# 의존성 다운로드 (캐시 최적화)
RUN ./gradlew dependencies --no-daemon

# 소스 코드 복사
COPY src src

# 빌드 실행
RUN ./gradlew clean build -x test --no-daemon

# jar 파일명 확인 및 실행
RUN ls -la build/libs/

# 환경변수로 PORT 설정
ENV PORT=8080
EXPOSE $PORT

# 정확한 jar 파일명으로 실행 (와일드카드 대신)
CMD ["sh", "-c", "java -Xmx400m -Dserver.port=${PORT} -jar build/libs/*.jar"]
