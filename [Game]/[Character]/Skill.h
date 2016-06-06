class Skill
{
private:
	int Damage;
	int TimePoint;
	int Skill_Num;//스킬넘버를 지정해줌으로써 적같은경우 랜덤으로 스킬을 사용해야하니 스킬번호로 랜덤공격하게 할 수 있다.

	float S_Xpos;
	float S_Ypos;
public:
	Skill(int sn, int dg, int tp);
	~Skill();

	int Return_Skill_Num();
	int Return_Damage();
	int Return_TimePoint();
};//스킬쓸때 이벡트로 이미지같은걸 여기서 관리해야할지는 나도 잘 모르겠다.. 아마 이미지 좌표이동정도는 여기서 해줘야겠지
