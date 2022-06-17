package hello.core.discount;

import hello.core.member.Member;

public interface DIscountPolicy {

    int discount(Member member, int price);

}
