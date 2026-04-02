// fanliangyi-dao.c 反兩儀刀法
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N手中$w斜指，一招"HIY"「混沌一破」"NOR"，反身一頓，一刀向$n的$l撩去",
	"lvl"    : 0,
	"skill_name" : "混沌一破",
]),
([	"action" : "$N一招"HIC"「太乙生萌」"NOR"，左右腿虛點，$w一提一收，平刃揮向$n的頸部",
	"lvl"    : 20,
	"skill_name" : "太乙生萌",
]),
([	"action" : "$N展身虛步，提腰躍落，一招"BLU"「兩儀合德」"NOR"，刀鋒化作兩股斬向$n",
	"lvl"    : 40,
	"skill_name" : "兩儀合德",
]),
([	"action" : "$N一招"HIW"「日月晦明」"NOR"，$w大開大闔，自上而下劃出一個大弧，筆直劈向$n",
	"lvl"    : 60,
	"skill_name" : "日月晦明",
]),
([	"action" : "$N手中$w一沉，一招"HIR"「無色無相」"NOR"，雙手持刃攔腰反切，砍向$n的胸口",
	"lvl"    : 80,
	"skill_name" : "無色無相",
]),
([	"action" : "$N揮舞$w，使出一招"HIB"「萬劫不復」"NOR"，上劈下撩，左擋右開，齊齊罩向$n",
	"lvl"    : 100,
	"skill_name" : "萬劫不復",
])
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 300)
		return notify_fail("你的內力不夠。\n");
	if ((int)me->query_skill("zixia-shengong", 1) < 50)
		return notify_fail("你的「紫霞神功」火候太淺。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if( !me->query_skill("zixia-shengong",1))
		return notify_fail("練「反兩儀刀法」必須要以「紫霞神功」為基礎。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不對。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的體力不夠練「反兩儀刀法」。\n");
	me->receive_damage("qi", 25);
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
	int d_e1 = 55;
	int d_e2 = 30;
	int p_e1 = 0;
	int p_e2 = -15;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 50;
	int m_e2 = 160;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("fanliangyi-dao", 1);
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
		"damage_type" : "割傷",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point() { return 1; }
string perform_action_file(string action)
{
	return __DIR__"fanliangyi-dao/" + action;
}
/*
int form_array(object leader)
//int perform(object leader, object target)
{
	object *member,ob, weapon;
	int i,j,n;
	int max,min,skill;

	member = leader->query_team();
	if( sizeof(member) != 2 )
		return notify_fail("反兩儀刀共需兩人，少一個多一個都不行。\n");

	j=sizeof (member);
	for (i=0;i<j;i++)
	{
		ob=member[i];
		if (!ob || !living(ob) || ob->query_temp("noliving") ||
			!ob->is_character())
		{
			return notify_fail("你想和誰同使反兩儀刀？\n");
		}
		if (ob->query_temp("array/name"))
		{
			return notify_fail("已經組成刀陣了。\n");
		}
		if (environment(leader)!=environment(ob))
		{
			return notify_fail("人數不夠兩人。\n");
		}
		if (!ob->query_skill("fanliangyi-dao",1))
		{
			return notify_fail(ob->name()+"還不會反兩儀刀法。\n");
		}
		if (ob->is_ghost())
		{
			return notify_fail("只有陽間的人才能組刀陣。\n");
		}

		if( (int)ob->query("max_neili") < 50 )
			return notify_fail(ob->query("name")+"的內力不夠。\n");

		if( (string)ob->query_skill_mapped("force")!= "zixia-shengong")
			return notify_fail(ob->query("name")+"沒有使用華山派內功。\n");

		if( !(weapon = ob->query_temp("weapon"))
			|| (string)weapon->query("skill_type") != "blade" )
			return notify_fail(ob->query("name")+"必須拿把刀做武器。\n");

		if( (int)ob->query_skill("fanliangyi-dao",1)<30)
			return notify_fail(ob->query("name")+"的反兩儀刀法還不夠熟練。\n");

		if( (string)ob->query_skill_mapped("blade")!="fanliangyi-dao")
			return notify_fail(ob->query("name")+"必須使用反兩儀刀法。\n");

	}

//get the average array skill of the team
	n=0;
	for (i=0;i<j;i++)
	{
		ob=member[i];
		n+=(int)ob->query_skill("fanliangyi-dao",1);
	}
	n/=2;

//get the difference of the array skill,
//first get the max and mix skill level of the array
	max=member[0]->query_skill("fanliangyi-dao",1);
	min=max;
	for (i=0;i<j;i++)
	{
		skill=member[i]->query_skill("fanliangyi-dao",1);
		if(skill>max)
			max=skill;
		else if(skill<min)
			min=skill;
	}

//and the leader is important
	n += leader->query_skill("fanliangyi-dao", 1) * 5;
	n /= max - min + 1;
	for (i=0;i<j;i++)
	{
		ob=member[i];
		ob->set_temp("no_quit",1);

		ob->set_temp("array/name","fanliangyi-dao");
		ob->set_temp("array/level",n);

		ob->add_temp("apply/attack",n);
		ob->add_temp("apply/defense", n);
		ob->add_temp("apply/damage",n);
		ob->add_temp("apply/armor", n);
	}
	message_combatd(HIG"$N率領$N站定兩儀方位，頓時兩人之間顯得渾然天成、毫無破綻。\n" NOR, leader);
	return 1;
}
int dismiss_array(object person)
{
	int i,j,n;
	object *member,ob;

	member = person->query_team();
	j=sizeof(member);
	n=person->query_temp("array/level");
	for (i=0;i<j;i++)
	{
		ob=member[i];
		ob->delete_temp("array");
		ob->add_temp("apply/attack",-n);
		ob->add_temp("apply/damage",-n);
		ob->add_temp("apply/defense",-n);
		ob->add_temp("apply/armor", -n);
		tell_object(ob,"刀陣解散了\n");
	}
}

//if the leader kills enemy, then all members in the array kill enemy
int array_kill(object leader, object enemy)
{
	object *member, ob;
	int i,j;
	member=leader->query_team();
	j=sizeof(member);

	for(i=0;i<j;i++)
	{
		ob=member[i];
		ob->kill_ob(enemy);
	}

	return 1;
}
int effective_level() { return 10;}
*/
int help(object me)
{
	write(HIC"\n反兩儀刀法："NOR"\n");
	write(@HELP

    反兩儀刀法是華山派功夫，兩儀化四象，四象化八卦，正變八
八六十四招，奇變八八六十四招，正奇相合，六十四再以六十四倍
之，共有四千零九十六種變化。天下武功變化之繁，可説無出其右
了。招數雖多，終究不脫於太極化為陰陽兩儀的道理。陽分太陽、
少陰，陰分少陽、太陰，是為四象。太陽為乾兌，少陰為離震，少
陽為巽坎，太陰為艮坤。乾南、坤北、離東、坎西、震東北、兌東
南、巽西南、艮西北。自震至乾為順，自巽至坤為逆。天地定位，
山澤通氣，雷風相薄，水火不相射，八卦相錯。數往者順，知來者
逆。正兩儀劍法，是自震位至乾位的順；華山派反兩儀刀法，則是
自巽位至坤位的逆。

	學習要求：
		紫霞神功50級
		內力300
HELP
	);
	return 1;
}

