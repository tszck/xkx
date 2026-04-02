// cuixin-strike.c 摧心掌

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N身形微晃，一招"CYN"「風催冰寒」"NOR"，掌挾冷風，推向$n的心房",
	"lvl"   : 0,
	"skill_name" : "風催冰寒",
]),
([	"action" : "$N出手如風，雙掌微微抖動，一招"BLU"「懾影寒心」"NOR"推向$n的胸腹",
	"lvl"   : 20,
	"skill_name" : "懾影寒心",
]),
([	"action" : "$N雙掌忽隱忽現，一招"HIW"「漫天雪舞」"NOR"，鬼魅般地掃向$n的肩頭",
	"lvl"   : 40,
	"skill_name" : "漫天雪舞",
]),
([	"action" : "$N左掌當胸畫弧，右掌疾出，一招"GRN"「飛熒罩影」"NOR"，猛地拍向$n的額頭",
	"lvl"   : 60,
	"skill_name" : "飛熒罩影",
]),
([	"action" : "$N使一招"HIC"「寒川歲盡」"NOR"，雙掌齊出，激起漫天的勁風，撞向$n",
	"lvl"   : 80,
	"skill_name" : "寒川歲盡",
]),
([	"action" : "$N面無表情，雙臂忽左忽右地疾揮，使出"HIM"「雪原冰凌」"NOR"，十股掌氣忽伸忽縮，迅猛無比地襲向$n全身各處大穴",
	"lvl"   : 100,
	"skill_name" : "雪原冰凌",
]),
([	"action" : "$N使出"RED"「旋風蔽日」"NOR"，驀然遊身而上，繞着$n疾轉數圈，$n正眼花繚亂間，$N已悄然停在$n身後，右手劃出一道光圈，接着右手衝出光圈猛拍$n的後背",
	"lvl"   : 120,
	"skill_name" : "旋風蔽日",
]),
([	"action" : "$N突然雙手平舉，$n一呆，正在猜測間，便見$N嗖的一下將雙手收回胸前，接着一招"HIG"「回首銀川」"NOR"，雙掌如電，直拍向$n的腰間",
	"lvl"   : 140,
	"skill_name" : "回首銀川",
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" ; }
int valid_combine(string combo) { return combo=="wuying-leg"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練摧心掌必須空手。\n");
	if ((int)me->query_skill("qingming-xuangong", 1) < 15)
		return notify_fail("你的青冥玄功火候不夠，無法學習摧心掌。\n");
	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("你的內功火候不夠，練摧心掌會走火入魔。\n");
	if ((int)me->query("max_neili") < 300)
		return notify_fail("你的內力太弱，無法練摧心掌。\n");
	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的內力不夠練摧心掌。\n");
	if (me->query_skill("cuixin-strike", 1) < 60)
		me->receive_damage("qi", 45);
	else
		me->receive_damage("qi", 40);
	me->add("neili", -25);
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
	int d_e1 = -45;
	int d_e2 = -25;
	int p_e1 = -5;
	int p_e2 = 25;
	int f_e1 = 200;
	int f_e2 = 310;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("cuixin-strike", 1);
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
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"cuixin-strike/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("cuixin-strike",1)) > 50)
	{
		victim->receive_damage("qi", random(10) + 1);
	}
}

int help(object me)
{
	write(HIC"\n摧心掌："NOR"\n");
	write(@HELP

    摧心掌為青城派歹毒掌法。摧毀敵方心臟。
    可與無影腿互備。

	學習要求：
		青冥玄功15級
		基本內功20級
		內力300
HELP
	);
	return 1;
}

