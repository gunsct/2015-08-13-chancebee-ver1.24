class Skill
{
private:
	int Damage;
	int TimePoint;
	int Skill_Num;//��ų�ѹ��� �����������ν� ��������� �������� ��ų�� ����ؾ��ϴ� ��ų��ȣ�� ���������ϰ� �� �� �ִ�.

	float S_Xpos;
	float S_Ypos;
public:
	Skill(int sn, int dg, int tp);
	~Skill();

	int Return_Skill_Num();
	int Return_Damage();
	int Return_TimePoint();
};//��ų���� �̺�Ʈ�� �̹��������� ���⼭ �����ؾ������� ���� �� �𸣰ڴ�.. �Ƹ� �̹��� ��ǥ�̵������� ���⼭ ����߰���
