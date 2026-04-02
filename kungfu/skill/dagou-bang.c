// dagou-bang.c 打狗棒法
// Last Modified by sir 10.22.2001
// write by Xiang

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action": "$N使出一招"HIG"「棒打雙犬」"NOR"，手中$w化作兩道青光砸向$n的$l",
	"lvl"        : 10,
	"skill_name" : "棒打雙犬"
]),
([	"action": "$N手中$w左右晃動，一招"HIG"「撥草尋蛇」"NOR"向$n的$l攻去",
	"lvl"        : 20,
	"skill_name" : "撥草尋蛇"
]),
([	"action": "$N舉起$w，居高臨下使一招"HIG"「打草驚蛇」"NOR"敲向$n的$l",
	"lvl"        : 30,
	"skill_name" : "打草驚蛇"
]),
([	"action": "$N施出"HIG"「撥狗朝天」"NOR"，$w由下往上向$n撩去",
	"lvl"        : 40,
	"skill_name" : "撥狗朝天"
]),
([	"action":"$N眼中射出一道青芒，手中綠玉棒使出"HIR"「天下無狗」"NOR"，劈天蓋地劈落",
	"lvl"        : 50,
	"skill_name" : "天下無狗"
]),
});

int valid_enable(string usage) { return (usage=="stick") || (usage=="parry"); }

int valid_learn(object me)
{
	if ((int)me->query_skill("huntian-qigong", 1) < 50)
		return notify_fail("你的混天氣功的火候還不夠。\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的內力不夠。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "stick")
		return notify_fail("你使用的武器不對。\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 50 )
		return notify_fail("你的內力或氣不夠練打狗棒法。\n");
	me->receive_damage("qi", 40);
	me->add("neili", -40);
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
	int d_e1 = -60;
	int d_e2 = -30;
	int p_e1 = -10;
	int p_e2 = 10;
	int f_e1 = 300;
	int f_e2 = 400;
	int m_e1 = 100;
	int m_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("dagou-bang", 1);
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
		"damage_type" : "挫傷",
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 5; }
int power_point() { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"dagou-bang/" + action;
}

int help(object me)
{
	write(HIC"\n打狗棒法："NOR"\n");
	write(@HELP

    三十六路打狗棒法是丐幫開幫祖師爺所創，歷來是前任幫主傳
後任幫主，決不傳給第二個人。丐幫第三任幫主的武功尤勝開幫祖
師，他在這路棒法中更加入無數奧妙變化。數百年來，丐幫逢到危
難關頭，幫主親自出馬，往往便仗這打狗棒法除奸殺敵，鎮懾羣邪。
    打狗棒法名字雖然陋俗，但變化精微，招術奇妙，實是古往今
來武學中第一等特異的功夫，卓然自成一家，與各門派的功夫均無
牽涉。單學招數，若是不明『絆、劈、纏、戳、挑、引、封、轉』
八字口訣，那是一點無用。每句口訣，須與每個招數相配，威力無
儔。為丐幫幫主歷代相傳的鎮幫之寶。

	學習要求：
		混天氣功50級
		內力200
HELP
	);
	return 1;
}

