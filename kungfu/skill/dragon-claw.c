// Last Modified by Winder on May. 29 2001
// dragon-claw.c 龍爪功 和般若掌互備 取自《倚天屠龍記》。

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "在呼呼風聲中，$N使一招"CYN"「捕風式」"NOR"，雙手如鈎如戢，緊隨$n，插向$p的$l",
	"lvl"    : 0,
	"skill_name" : "捕風式" ,		
]),
([	"action" : "$N猛地向前躍出，一招"BLU"「捉影式」"NOR"，身隨$n遊走，左右雙手連抓，招招不離$n的面門",
	"lvl"    : 10,
	"skill_name" : "捉影式" ,		
]),
([	"action" : "$N雙手平伸，十指微微上下抖動，打向$n的$l，這是一招華麗的"GRN"「撫琴式」"NOR"",
	"lvl"    : 20,
	"skill_name" : "撫琴式" ,		
]),
([	"action" : "$N左手上攔，右手內揮空抓，仿若握拳，一招"YEL"「擊鼓式」"NOR"擊向$n胸口，卻是力大無比",
	"lvl"    : 30,
	"skill_name" : "擊鼓式" ,		
]),
([	"action" : "$N右手虛握，左手掌立如山，一招"MAG"「批亢式」"NOR"，突然變招，左收右出，猛地擊向$n的$l",
	"lvl"    : 40,
	"skill_name" : "批亢式" ,		
]),
([	"action" : "$N騰步上前，左手護胸，右手探出，這一招"HIW"「掏虛式」"NOR"抓向$n的$l，使得痛快淋漓",
	"lvl"    : 50,
	"skill_name" : "掏虛式" ,		
]),
([	"action" : "$N雙手平提胸前，左手護住面門，一招"HIB"「抱殘式」"NOR"，身體一轉，閃在$n身旁，右手推向$p的$l",
	"lvl"    : 60,
	"skill_name" : "抱殘式" ,		
]),
([	"action" : "$N兩手胸前環抱，腋下含空，一爪而出，五指如鈎，一招"HIM"「守缺式」"NOR"插向$n的頂門",
	"lvl"    : 70,
	"skill_name" : "守缺式" ,		
]),
([	"action" : "$N右腿斜插$n二腿之間，一招"HIR"「搶珠式」"NOR"，上手取目誘敵，下手反勾$n的$l",
	"lvl"    : 80,
	"skill_name" : "搶珠式" ,		
]),
([	"action" : "$N一手虛指$n的劍訣，一招"CYN"「奪劍式」"NOR"，一手劈空抓向$n，抓內中空，彷彿握有長劍",
	"lvl"    : 100,
	"skill_name" : "奪劍式" ,		
]),
([	"action" : "$N左手抓向$n胸前的五道大穴，右手斜劈太陽穴，一招"HIW"「拿雲式」"NOR"使得$n進退兩難",
	"lvl"    : 120,
	"skill_name" : "拿雲式" ,		
]),
([	"action" : "$N前腳着地，一手頂天成爪，一手指地，一招"RED"「追日式」"NOR"後出先至，勁氣籠罩$n的全身",
	"lvl"    : 150,
	"skill_name" : "追日式" ,		
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }
int valid_combine(string combo){ return combo=="boruo-strike"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練龍爪功必須空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 80)
		return notify_fail("你的站樁功火候不夠，無法學龍爪功。\n");
	if ((int)me->query("max_neili") < 800)
		return notify_fail("你的內力太弱，無法練龍爪功。\n");
	if ((me->query_skill("nianhua-finger", 1) < 50) ||
		(me->query_skill("eagleg-claw", 1) < 50))
		return notify_fail("你的拈花指和鷹爪功火候不夠，無法學龍爪功。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 55)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的內力不夠練龍爪功。\n");
	me->receive_damage("qi", 50);
	me->add("neili", -20);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 30;
	int d_e2 = 5;
	int p_e1 = -20;
	int p_e2 = -50;
	int f_e1 = 300;
	int f_e2 = 450;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("dragon-claw", 1);
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
		"damage_type" : random(2) ? "內傷" : "抓傷",
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 5; }
int success() { return 10; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"dragon-claw/" + action;
}

int help(object me)
{
	write(HIC"\n龍爪功："NOR"\n");
	write(@HELP

    龍爪功是南少林爪法，和般若掌互備。

	學習要求：
		站樁功80級
		拈花指50級
		鷹爪功50級
		內力修為800
HELP
	);
	return 1;
}

