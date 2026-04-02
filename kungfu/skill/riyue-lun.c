// riyue-lun.c 日月輪法
// Last Modified by sir 10.23.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N使一招"GRN"「破竹勢」"NOR"，掄起手中的$w向$n的$l砸去",
	"skill_name" : "破竹勢",
	"lvl" : 0
]),
([	"action" : "$N使一招"BLU"「隱山谷勢」"NOR"，雙肩一沉，舞動手中$w向$n的$l橫掃",
	"skill_name" : "隱山谷勢",
	"lvl" : 8
]),
([	"action" : "$N使一招"MAG"「隱微勢」"NOR"，就地一滾，手中自下而上撩向$n的$l",
	"skill_name" : "隱微勢",
	"lvl" : 16
]),
([	"action" : "$N使一招"RED"「擒縱勢」"NOR"，身形起伏之際$w掃向$n的$l",
	"skill_name" : "擒縱勢",
	"lvl" : 24
]),
([	"action" : "$N使一招"YEL"「圓滿勢」"NOR"，$w如離弦之箭般直搗$n的$l",
	"skill_name" : "圓滿勢",
	"lvl" : 32
]),
([	"action" : "$N躍入半空，使一招"HIC"「月重輝勢」"NOR"，高舉$w敲向$n的$l",
	"skill_name" : "月重輝勢",
	"lvl" : 40
]),
([	"action" : "$N使一招"HIW"「捉月勢」"NOR"，斜舉手中$w擊向$n的$l",
	"skill_name" : "捉月勢",
	"lvl" : 48
]),
([	"action" : "$N提一口真氣，使出"HIR"「顯吉祥」"NOR"，$w掃向$n的頭部",
	"skill_name" : "顯吉祥",
	"lvl" : 56
]),
});

int valid_enable(string usage) { return usage == "hammer" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的內力不夠。\n");
	if ((int)me->query_skill("longxiang", 1) < 20)
		return notify_fail("你的龍象般若功火候太淺。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "hammer")
		return notify_fail("你使用的武器不對。\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 50 )
		return notify_fail("你的內力或氣不夠,練不了日月輪法。\n");
	me->receive_damage("qi", 40);
	me->add("neili", -40);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	object my_w, victim_w;
	object piece;
	victim_w = victim->query_temp("weapon");
	my_w = victim->query_temp("weapon");

//	if( me->query("dex") < 20 || me->query("str") < 20 )

	if (victim->query_temp("weapon") || victim->query_temp("secondary_weapon"))
	{
		if( (int)(me->query_skill("riyue-lun", 1)) < 20 )
			return HIW"一陣兵刃相撞的聲音過後，對方兵器居然完好無損。\n"NOR;
		if( random(victim->query_temp("apply/damage")) < random(me->query_skill("riyue-lun", 1)/3 ) )
		{
			if (objectp(my_w = me->query_temp("weapon")) &&
				((string)my_w->query("id") == "fa lun" 
                                  ||(string)my_w->query("id")=="yin lun"
                                   ||(string)my_w->query("id")=="jin lun" ) 
                                   && my_w->query("ownmake") != 1)
			{
				seteuid(getuid());
				piece = new("/clone/misc/piece");
				piece->set_name(victim_w->query("name") + "的碎片",({victim_w->query("id"),"piece"}));
        piece->move(environment(victim));
				piece->set("long", "一堆破碎物事，好象是兵器碎片。\n");
				destruct(victim_w);
				return HIB "你聽到「叮噹」一聲兵刃破碎的聲音，兵器碎片濺了一地！\n" NOR;
			}
			else return HIR"可惜你沒用法輪，沒法砸碎對方兵器！\n"NOR;
		}
	}
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
	int d_e1 = 20;
	int d_e2 = 40;
	int p_e1 = -40;
	int p_e2 = -20;
	int f_e1 = 300;
	int f_e2 = 400;
	int m_e1 = 100;
	int m_e2 = 250;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("riyue-lun", 1);
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
int success() { return 15; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n日月輪法："NOR"\n");
	write(@HELP

    日月輪法爲金輪法王的武功，是雪山寺極爲霸道的功夫。

	學習要求：
		龍相般若功20級
		內力100
HELP
	);
	return 1;
}

