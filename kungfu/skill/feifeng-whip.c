// feifeng-whip.c 飛鳳鞭法
// Last Modified by sir 10.20.01

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N向上躍起，一招"MAG"「鳳凰展翅」"NOR"，手中$w自下而上，擊向$n的臉頰",
	"lvl"    : 0,
	"skill_name" : "鳳凰展翅",
]),
([	"action" : "$N一招"MAG"「綵鳳棲梧」"NOR"，手中$w直繞向$n的$l",
	"lvl"    : 20,
	"skill_name" : "綵鳳棲梧",
]),
([	"action" : "$N一招"HIY"「鸞鳳和鳴」"NOR"，手中$w騰空一卷，一聲脆響入磬，猛地向$n劈頭打下",
	"lvl"    : 40,
	"skill_name" : "鸞鳳和鳴",
]),
([	"action" : "$N踏上一步，衝着$n輕佻一笑，手中$w卻毫不停留，一招"HIG "「遊龍戲鳳」"NOR"，掃向$n的$l",
	"lvl"    : 50,
	"skill_name" : "遊龍戲鳳",
]),
([	"action" : "$N躍在半空，一招"HIR"「龍飛鳳舞」"NOR"，手中$w如遊龍洗空，長鳳戲羽，亂雨傾盆般分點$n左右",
	"lvl"    : 60,
	"skill_name" : "龍飛鳳舞",
]),
([	"action" : "$N向前急進，手中$w圈轉如虹，一招"HIM"「龍鳳呈祥」"NOR"，罩向$n前胸",
	"lvl"    : 75,
	"skill_name" : "龍鳳呈祥",
])
});

int valid_enable(string usage) { return (usage=="whip") || (usage=="parry"); }

int valid_learn(object me)
{
	object weapon;

	if ((int)me->query_skill("kurong-changong", 1) < 20)
		return notify_fail("你的枯榮禪功火候太淺。\n");
	if ((int)me->query("max_neili") < 300)
		return notify_fail("你的內力不夠。\n");
	if ( me->query("gender") != "女性")
		return notify_fail("大老爺們學這飛鳳鞭？天資不足吧。\n");
	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "whip" )
		return notify_fail("你必須先找一條長鞭才能練鞭法。\n");

	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不對。\n");
	if( (int)me->query("qi") < 5 || (int)me->query("neili") < 5 )
		return notify_fail("你的體力不夠練飛鳳鞭法。\n");
	me->receive_damage("qi", 5);
	me->add("neili", -5);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
	int d_e1 = -40;
	int d_e2 = -35;
	int p_e1 = 5;
	int p_e2 = 20;
	int f_e1 = 50;
	int f_e2 = 100;
	int m_e1 = 100;
	int m_e2 = 200;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("feifeng-whip", 1);
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
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : random(2) ? "瘀傷": "刺傷",
	]);
}

int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point() { return 1.0; }

int help(object me)
{
	write(HIC"\n飛鳳鞭法："NOR"\n");
	write(@HELP

    飛鳳鞭法為天南大理段家的武功。大理鎮南王段正淳妻子刀白
鳳成名絕技，唯女子能學。

	學習要求：
		女性
		枯榮禪功20級
		內力100
HELP
	);
	return 1;
}

