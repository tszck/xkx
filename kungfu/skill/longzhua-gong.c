// longzhua-gong.c 龍爪功
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "在呼呼風聲中，$N使一招"GRN"「捕風式」"NOR"，雙手如鉤如戢，插向$n的$l",
	"lvl"    : 0,
	"skill_name" : "捕風式" ,
]),
([	"action" : "$N猛地向前躍出，一招"HIB"「捉影式」"NOR"，兩腿踢出，雙手抓向$n的面門",
	"lvl"    : 6,
	"skill_name" : "捉影式" ,
]),
([	"action" : "$N雙手平伸，十指微微上下抖動，一招"HIC"「撫琴式」"NOR"打向$n的$l",	
	"lvl"    : 12,
	"skill_name" : "撫琴式" ,
]),
([	"action" : "$N左手上攔，右手內揮，一招"RED"「擊鼓式」"NOR"擊向$n胸口",
	"lvl"    : 18,
	"skill_name" : "擊鼓式" ,
]),
([	"action" : "$N右手虛握，左手掌立如山，一招"HIM"「批亢式」"NOR"，猛地擊向$n的$l",
	"lvl"    : 24,
	"skill_name" : "批亢式" ,
]),
([	"action" : "$N騰步上前，左手護胸，右手探出，一招"YEL"「掏虛式」"NOR"擊向$n的襠部",
	"lvl"    : 30,
	"skill_name" : "掏虛式" ,
]),
([	"action" : "$N雙手平提胸前，左手護住面門，一招"HIY"「抱殘式」"NOR"右手推向$n的$l",
	"lvl"    : 35,
	"skill_name" : "抱殘式" ,
]),
([	"action" : "$N兩手胸前環抱，腋下含空，五指如鉤，一招"HIC"「守缺式」"NOR"插向$n的頂
門",
	"lvl"    : 40,
	"skill_name" : "守缺式" ,
]),
([	"action" : "$N右腿斜插$n二腿之間，一招"HIB"「搶珠式」"NOR"，上手取目，下手反勾$n的
襠部",
	"lvl"    : 45,
	"skill_name" : "搶珠式" ,
]),
([	"action" : "$N一手虛指$n的劍訣，一招"HIR"「奪劍式」"NOR"，一手劈空抓向$n手中的長劍
",
	"lvl"    : 50,
	"skill_name" : "奪劍式" ,
]),
([	"action" : "$N左手指向$n胸前的五道大穴，右手斜指太陽穴，一招"HIW"「拿雲式」"NOR"使
$n進退兩難",
	"lvl"    : 55,
	"skill_name" : "拿雲式" ,
]),
([	"action" : "$N前腳着地，一手頂天成爪，一手指地，一招"HIY"「追日式」"NOR"勁氣籠罩$n
的全身",
	"lvl"    : 60,
	"skill_name" : "追日式" ,
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }
int valid_combine(string combo) { return combo=="qianye-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練龍爪功必須空手。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("你的混元一氣功火候不夠，無法學龍爪功。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的內力太弱，無法練龍爪功。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必須空手才能練習。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的內力不夠練龍爪功。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
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
	int d_e2 = 10;
	int p_e1 = -15;
	int p_e2 = -50;
	int f_e1 = 300;
	int f_e2 = 450;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("longzhua-gong", 1);
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
int power_point() { return 1; }

int help(object me)
{
	write(HIC"\n龍爪功："NOR"\n");
	write(@HELP

    龍爪功只有三十六招，要旨端在凌厲狠辣，不求變化繁多。爲
少林七十二絕技之一。
    可與如來千葉手互備。

	學習要求：
		混元一氣功20級
		內力100
HELP
	);
	return 1;
}

