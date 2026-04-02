// Last Modified by Winder on May. 29 2001
// eagleg-claw.c 鷹爪功 和捻花指互備

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N全身拔地而起，半空中一個筋斗，一式"HIB"「兇鷹襲兔」"NOR"，迅猛地抓向$n的$l",
	"lvl"   : 0,
	"skills_name" : "兇鷹襲兔",
]),
([	"action" : "$N單腿直立，雙臂平伸，全身一轉，一式"HIY"「雄鷹展翅」"NOR"，雙爪一前一後攏向$n的$l",
	"lvl"   : 10,
	"skills_name" : "雄鷹展翅",
]),
([	"action" : "$N一式"HIM"「拔翅橫飛」"NOR"，全身向斜裏平飛，右腿一繃，雙爪飛落，搭向$n的$l",
	"lvl"   : 20,
	"skills_name" : "拔翅橫飛",
]),
([	"action" : "$N雙爪交錯上舉，使一式"HIC"「迎風振翼」"NOR"，一拔身，凌空而起，分別襲向$n左右空門",
	"lvl"   : 30,
	"skills_name" : "迎風振翼",
]),
([	"action" : "$N全身滾動上前，一式"HIM"「飛龍獻爪」"NOR"，爪影中右爪猛地突出，鬼魅般抓向$n的胸口",
	"lvl"   : 40,
	"skills_name" : "飛龍獻爪",
]),
([	"action" : "$N伏地滑行，一式"HIW"「撥雲瞻日」"NOR"，雙抓一翻，上手襲向膻中大穴，下手反抓$n的$l",
	"lvl"   : 50,
	"skills_name" : "撥雲瞻日",
]),
([	"action" : "$N左右手掌爪互逆，躍起一式"CYN"「搏擊長空」"NOR"，無數道勁氣直指尖破空而出，迅疾無比地擊向$n",
	"lvl"   : 55,
	"skills_name" : "搏擊長空",
]),
([	"action" : "$N騰空高飛三丈，一式"RED"「鷹揚萬裏」"NOR"，長嘯一聲，於天空中幻化出一個巨靈爪影，緩緩罩向$n",
	"lvl"   : 60,
	"skills_name" : "鷹揚萬裏",
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }
int valid_combine(string combo){ return combo=="nianhua-finger"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練鷹爪功必須空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 60)
		return notify_fail("你的易筋經內功火候不夠，無法學鷹爪功。\n");
	if ((int)me->query("max_neili") < 600)
		return notify_fail("你的內力太弱，無法練鷹爪功。\n");
	if ((me->query_skill("jimie-claw", 1) < 50) ||
		(me->query_skill("jingang-strike", 1) < 50))
		return notify_fail("你的大金剛神掌和寂滅爪火候不夠，無法學鷹爪功。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的內力不夠練鷹爪功。\n");
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
	int d_e1 = 50;
	int d_e2 = 20;
	int p_e1 = -10;
	int p_e2 = -30;
	int f_e1 = 200;
	int f_e2 = 350;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("eagleg-claw", 1);
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
		"damage_type" : random(2) ? "瘀傷" : "抓傷",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	 return __DIR__"eagleg-claw/" + action;
}

int help(object me)
{
	write(HIC"\n鷹爪功："NOR"\n");
	write(@HELP

    鷹爪功是南少林爪法，和拈花指互備。

	學習要求：
		站樁功60級
		大金剛神掌50級
		寂滅爪50級
		內力修爲600
HELP
	);
	return 1;
}

