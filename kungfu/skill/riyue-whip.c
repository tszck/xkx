// riyue-whip.c 日月鞭法
// Last Modified by sir 10.20.01

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N端坐不動，一式"HIG"「阿那律刺」"NOR"，手腕力抬，$w滾動飛舞，宛如靈蛇亂顫，前纏後繞，其力沾粘不散",
	"lvl"    : 0,
	"skill_name" : "阿那律刺",
]),
([	"action" : "$N一式"HIM"「目捷連刺」"NOR"，將手$w中抖得筆直，“呲呲”聲中向$n疾刺而至，所挾勁風已令$n一陣氣窒",
	"lvl"    : 30,
	"skill_name" : "目捷連刺",
]),
([	"action" : "$N內勁到處，將$w抖動轉成兩個圓圈，一式"HIW"「舍利佛刺」"NOR"，躍起從半空中往$n$l纏下",
	"lvl"    : 60,
	"skill_name" : "舍利佛刺",
]),
([	"action" : "$N勁走螺旋，一式"BLU"「富樓那刺」"NOR"，$w在$n眼前上圈下鈎，左旋右轉，連變了數種招式，忽然從$n$l處倒捲上來",
	"lvl"    : 90,
	"skill_name" : "富樓那刺",
]),
([	"action" : "$N一聲高喝，吸氣催力，一式"HIB"「迦旋延刺」"NOR"，$w急速轉動，鞭影縱橫，直中有圓，圓中有直，似真似幻，絞向$n",
	"lvl"    : 120,
	"skill_name" : "迦旋延刺",
]),
([	"action" : "$N含胸拔背、沉肩墜肘，一式"MAG"「弘忍能刺」"NOR"，力道靈動威猛，虛實分明，勁力從四面八方向$n擠壓出去",
	"lvl"    : 150,
	"skill_name" : "弘忍能刺",
]),
});

int valid_enable(string usage) { return usage == "whip" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query_skill("ranmu-blade",1) > 1 ||
		(int)me->query_skill("weituo-chu",1)>1)
		return notify_fail("你如果有達摩老祖的修為，方可同時學習南少林三絕技。\n");
	if ((int)me->query("max_neili") < 1500)
		return notify_fail("你的內力修為不足，沒有辦法練日月鞭法。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 150)
		return notify_fail("你的站樁功火候太淺。\n");
	if ((int)me->query_skill("yijinjing", 1) < 150)
		return notify_fail("你的易筋經神功火候太淺。\n");
	if((int)me->query_skill("xiangmo-whip",1) < 150)
		return notify_fail("你的降魔鞭火候不足，難以領悟日月鞭法。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不對。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的體力不夠練日月鞭法。\n");
	if ((int)me->query("neili") < 50 )
		return notify_fail("你的內力不夠練日月鞭法。\n");
	me->receive_damage("qi",30);
	me->add("neili",-30);	
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
	int d_e1 = -60;
	int d_e2 = -45;
	int p_e1 = -30;
	int p_e2 = -5;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 400;
	int m_e2 = 550;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("riyue-whip", 1);
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
		"damage_type" : random(2) ? "瘀傷" : "刺傷",
	]);
}

int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"riyue-whip/" + action;
}
int help(object me)
{
        write(HIC"日月鞭法："NOR"\n");
        write(@HELP

    日月鞭法是南少林頂級鞭法。
    韋陀杵、日月鞭法和燃木刀法並列為南少林三絕技。
    三絕技不能同時修習。

        學習要求：
                易筋經150級
                站樁功150級
                降魔鞭150級
                內力修為1500
HELP
        );
        return 1;
}

