// taixuan-gong.c 俠客島太玄功
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

string *dodge_msg = ({
	"$n左手拍出，勁風到處，把$N震到一邊。\n",
	"$n手臂迴轉，抓住$N手肘一推，將$N遠遠擲開。\n",
	"$n兩腿輕蹬，激躍而出，竟已落在十數丈外。\n",
	"$N只覺眼前一花，只見到$n身形一幌，自己的招數居然莫名其妙就落空了。\n",
});

mapping *action = ({
([	"action":"$N雙手一舉，一股勁氣澎湃洶湧而來，逼得$n踉踉後退",
	"lvl": 0
]),
([	"action":"$N右手伸出，在$n臂膀上迅速無比的一按，$n一跤跌了出去",
	"lvl": 10
]),
([	"action":"$N大喝一聲，張口一股內氣向$n臉上噴去",
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
	return usage == "unarmed" || usage == "dodge" || usage == "parry" || usage == "force";
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 30;
	int d_e2 = 50;
	int p_e1 = -30;
	int p_e2 = 10;
	int f_e1 = 440;
	int f_e2 = 600;	
	int i, lvl, seq, ttl = sizeof(action);
	if (random(me->query_skill("taixuan-gong",1)) > 220 && me->query("neili") > 100)
	{
		me->add("neili", -50);
		return ([
	"action": HIR "$N的心中突然一片茫然，只覺得經脈中象有無數的蝌蚪在串來串去，難過非常，
當下不及多想，順着蝌蚪的走向一陣拳打腳踢！四周頓時勁風亂颮，好不熱鬧！"NOR,
//	"damage": 1000,
  "parry" : -80,
  "dodge" : -40,
	"force" : 1000,
	"damage_type": "瘀傷"]);
	}
	lvl = (int) me->query_skill("taixuan-gong", 1);
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

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
int valid_learn(object me)
{
	return notify_fail("你想領會太玄功，只能到俠客島去面壁。\n");
}
string exert_function_file(string func)
{
	return __DIR__"taixuan-gong/" + func;
}
int help(object me)
{
	write(HIC"\n太玄功："NOR"\n");
	write(@HELP

    太玄功源自俠客島上洞壁武功。

	學習要求：
		各人自己的福緣
HELP
	);
	return 1;
}

