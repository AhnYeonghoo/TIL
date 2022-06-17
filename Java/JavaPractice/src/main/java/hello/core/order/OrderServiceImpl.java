package hello.core.order;

import hello.core.discount.DIscountPolicy;
import hello.core.discount.FixDiscountPolicy;
import hello.core.discount.RateDiscountPolicy;
import hello.core.member.Member;
import hello.core.member.MemberRepository;
import hello.core.member.MemoryMemberRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;


@Component
public class OrderServiceImpl implements OrderService {

    private MemberRepository memberRepository;
    private DIscountPolicy dIscountPolicy;

    @Autowired private DIscountPolicy rateDiscountPolicy;

    public MemberRepository getMemberRepository() {
        return memberRepository;
    }

    @Autowired
    public OrderServiceImpl(MemberRepository memberRepository, DIscountPolicy rateDiscountPolicy) {
        this.memberRepository = memberRepository;
        this.dIscountPolicy = rateDiscountPolicy;
    }

    @Override
    public Order createOrder(Long memberId, String itemName, int itemPrice) {

        Member member = memberRepository.findById(memberId);
        int discountPrice = dIscountPolicy.discount(member, itemPrice);

        return new Order(memberId, itemName, itemPrice, discountPrice);
    }

    @Autowired
    public void setMemberRepository(MemberRepository memberRepository) {
        this.memberRepository = memberRepository;
    }

    @Autowired
    public void setDiscountPolicy(DIscountPolicy dIscountPolicy) {
        this.dIscountPolicy = dIscountPolicy;
    }

}
