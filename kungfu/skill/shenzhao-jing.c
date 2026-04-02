// shenzhao-jing.c 神照經
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

mapping *action = ({
([	"action":"$N一躍跳到$n左側，手肘撞處，擊向$n上腹",
	"lvl": 0
]),
([	"action":"$N右手伸出，在$n臂膀上迅速無比的一按，$n一跤跌了出去",
	"lvl": 10
]),
([	"action":"$N大喝一聲，雙臂一舉，便在同時，膝蓋猛地上挺，撞向$n下襠",
	"lvl": 20
]),
([	"action":"$N猱身而上，雙掌猛地拍向$n",
	"lvl": 30
]),
([	"action":"$N身體微側，突然飛起一腳，踢向$n下三路。腳到中途，猛地一抬，踢向$n面門",
	"lvl": 40
]),
([	"action":"$N突然間左手一捺，封住$n退路，右手掌力洶湧而出",
	"lvl": 50
]),
});

int valid_enable(string usage)
{
	return usage == "unarmed" || usage == "parry" || usage == "force";
}
int valid_learn(object me)
{
	object ding;
	if(!objectp(ding=present("ding dian",environment(me))) || !living(ding))
		return notify_fail("你必須得到丁典指導，才能學神照經。\n");
	if (me->query("cps")+me->query("cor") !=
		ding->query("cps")+ding->query("cor") )
		return notify_fail("丁典看了看你，喘息着道：我現在實在太累讓我靜會兒。\n");
	if ((me->query("kar")%4) > 0 )
		return notify_fail("丁典搖了搖頭道：這門內功太過艱險了。不學也罷。\n");
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("神照經只能用學(learn)的來增加熟練度。\n");
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 25;
	int d_e2 = 45;
	int p_e1 = -30;
	int p_e2 = 10;
	int f_e1 = 140;
	int f_e2 = 240;	
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("shenzhao-jing", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* 獲得招數序號上限 */
			break;
		}
	seq = random(seq);       /* 選擇出手招數序號 */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,		
		"damage_type" : random(2) ? "內傷" : "瘀傷",
	]);
}

string exert_function_file(string func)
{
	return __DIR__"shenzhao-jing/" + func;
}
int help(object me)
{
	write(HIC"\n神照經："NOR"\n");
	write(@HELP

    丁典是荊門人，出生於武林世家。父母雙亡，家財不少，卻不
想結親，只是勤於練武，結交江湖上的朋友。
    某次他乘船從四川下來，出了三峽後，船泊在三鬥坪。晚上，
在船中聽得岸上有打鬥的聲音。從窗中向外張望。那晚月光明亮，
看得清清楚楚，是三個人在圍攻一個老者。一個是五雲手萬震山。
另一個是陸地神龍言達平。第三個人使一口長劍，身手甚是矯捷，
那是鐵鎖橫江戚長髮。老者便是鐵骨墨萼梅念笙。他們的師父。梅
念笙受傷在先，抵敵不住三個徒弟的毒招，跳江而逃。
    丁典身邊帶得有金創藥，救起梅念笙後，便替他治傷。可是他
背上那一劍刺得好深，穿通了肺，這傷是治不好的了。這麼治了三
天，梅念笙從懷中取出一個油紙包來交給丁典，道：“我在這世上
的親人，就這麼三個徒兒。他們想奪我一部劍譜，可是沒有劍訣，
那又有什麼用？連城劍法雖然神奇，又怎及得上神照經了？這部神
照經，我送了給你，好好地練罷，此經若然練成，威力奇大，千萬
不可誤傳匪人。”神照經，就是這樣來的。

	學習要求：
		憑機緣向丁典學習
HELP
	);
	return 1;
}

