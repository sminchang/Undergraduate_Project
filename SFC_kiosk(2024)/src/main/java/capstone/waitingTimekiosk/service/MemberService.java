package capstone.waitingTimekiosk.service;

import capstone.waitingTimekiosk.controller.AuthController;
import capstone.waitingTimekiosk.domain.Member;
import capstone.waitingTimekiosk.repository.MemberRepository;
import com.fasterxml.jackson.core.JsonProcessingException;
import lombok.RequiredArgsConstructor;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Service;


@Service
@RequiredArgsConstructor
public class MemberService {

    private final MemberRepository memberRepository;
    private final KakaoApi kakaoApi;
    private final Logger logger = LoggerFactory.getLogger(AuthController.class);


    //email 중복 회원 검증
    public Long validateDuplicateMember(Member member) {
        try{
            return memberRepository.findByEmail(member.getEmail()).getId();
        } catch (Exception e) {
            return memberRepository.save(member);}
    }

    //accessToken으로 회원 정보조회
    public Member findMember(String accessToken) throws JsonProcessingException {
        // 테스트 토큰이면 DB에서 ID=1인 회원 반환
        if (accessToken.startsWith("test_token_")) {
            return memberRepository.findById(1L);
        }
        
        Member member = kakaoApi.getUserInfo(accessToken);
        return memberRepository.findByEmail(member.getEmail());
    }

}
