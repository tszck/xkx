// shigu-bifa.c 石鼓打穴筆法
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action": "$N一招"HIG"「指點江山」"NOR"，手中$w疾點向$n的期門穴!",
	"lvl" : 0,
	"skill_name" : "指點江山"
]),
([	"action": "$N吐氣開聲一招"HIB"「銀鈎鐵劃」"NOR"，$w如靈蛇吞吐，向$n白海穴戳去!",
	"lvl" : 9,
	"skill_name": "銀鈎鐵劃"
]),
([	"action": "$N向前跨上一步，混身充滿戰意，手中$w使出"CYN"「銀瓶乍破」"NOR"，疾點$n的地倉穴!",
	"lvl" : 19,
	"skill_name" : "銀瓶乍破"
]),
([	"action": "$N手中的$w自左而右地一晃，使出"BLU"「鐵騎突出」"NOR"帶着呼呼風聲橫打$n的章門穴!",
	"lvl" : 29,
	"skill_name": "鐵騎突出"
]),
([	"action": "$N飛身躍起，一式"MAG"「龍耀九霄」"NOR"，捲起漫天筆影，$w向$n電射而去",
	"lvl" : 39,
	"skill_name": "龍耀九霄"
]),
([	"action": "$N凝氣守中，$w逼出尺許雪亮筆鋒，揮出"GRN"「靈臺觀景」"NOR"，一筆快似一筆地攻向$n",
	"lvl" : 59,
	"skill_name": "靈臺觀景"
]),
([	"action": "$N使出一招"HIW"「遙拜玉虛」"NOR"挺筆中宮直進，筆尖顫動，中途忽然轉而向上變幻無方",
	"lvl" : 79,
	"skill_name": "遙拜玉虛"
]),
([	"action": "$N側身斜刺一筆，一招"HIC"「天音蕭煞」"NOR"卷帶着呼呼筆風，將$n包圍緊裹",
	"lvl" : 99,
	"skill_name": "天音蕭煞"
]),
});

int valid_enable(string usage) { return usage == "dagger" || usage == "parry";}
int valid_learn(object me)
{
	if( (int)me->query("max_neili") < 100 )
		return notify_fail("你的內力不夠，沒有辦法練石鼓打穴。\n");
	if( (string)me->query_skill_mapped("force")!= "kuihua-xinfa")
		return notify_fail("石鼓打穴筆法需配合葵花心法。\n");
	if( (int)me->query_skill("kuihua-xinfa",1) < 20 )
		return notify_fail("你的葵花心法火候不夠，還不能學習石鼓打穴筆法!\n");
	return 1;
}
int practice_skill(object me)
{
	object ob;
	if( !(ob = me->query_temp("weapon")) ||
		(string)ob->query("skill_type") != "dagger" )
		return notify_fail("你必須先找一對判官筆才能學習石鼓打穴筆法。\n");
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 30 )
		return notify_fail("你的內力或氣不夠，沒有辦法練習石鼓打穴筆法。\n");
	me->receive_damage("qi", 20);
	me->add("neili", -20);
//	write("你按著所學練了一遍石鼓打穴筆法。\n");
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
	int d_e1 = 0;
	int d_e2 = 20;
	int p_e1 = -40;
	int p_e2 = -30;
	int f_e1 = 250;
	int f_e2 = 300;
	int m_e1 = 400;
	int m_e2 = 600;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("shigu-bifa", 1);
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
		"damage_type" : "刺傷",
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__ "shigu-bifa/" + action;
}

int help(object me)
{
	write(HIC"\n石鼓打穴筆法："NOR"\n");
	write(@HELP

    日月神教黑木崖武功，梅莊三莊主禿筆翁看家本領，以判官筆
書寫各名家碑帖，招招鐵劃銀鈎，沉猛有力。

	學習要求：
		葵花心法20級
		內力100
HELP
	);
	return 1;
}

