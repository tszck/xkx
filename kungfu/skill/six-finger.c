// six-fingers.c 六脈神劍
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"skill_name" : "少商劍",
	"action": "$N反過手來，雙手拇指同時捺出，嗤嗤兩聲急響，“少商劍”
有如石破天驚、風雨大至之勢，分指$n膻中和$l",
	"lvl"   : 0
]),
([	"skill_name" : "商陽劍",
	"action": "$N食指連動，手腕園轉，“商陽劍”一劍又一劍的刺出，輕靈
迅速，奇巧活潑，劍氣縱橫，$n根本無法看清來路",
	"lvl"   : 10
]),
([	"skill_name" : "中衝劍",
	"action": "$N右手中指一豎，“中衝劍”向前刺出。真氣鼓盪，嗤然聲響，
無形劍氣直指$n的$l",
	"lvl"   : 20
]),
([	"skill_name" : "關衝劍",
	"action": "$N右手無名指伸出，“關衝劍”劍路拙滯古樸，一股雄渾的內
力鼓盪而出，如排山倒海般向$n湧去",
	"lvl"   : 30
]),
([	"skill_name" : "少澤劍",
	"action": "$N左手小指一伸，一條氣流從少衝穴中激射而出，“少澤劍”
出手入風，指向$n的$l",
	"lvl"   : 40
]),
([	"skill_name" : "少衝劍",
	"action": "$N右手反指，小指伸出，真氣自少衝穴激盪而出，“少澤劍”
橫生奇變，從$n意想不到的方向刺向$n的$l",
	"lvl"   : 50
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練六脈神劍必須空手。\n");
	if ((int)me->query("max_neili") < 1200)
		return notify_fail("你的內力太弱，無法學六脈神劍。\n");
	if ((int)me->query_skill("kurong-changong",1) < 120)
		return notify_fail("你的枯榮禪功太低，無法學六脈神劍。\n");
	return 1;
}
int practice_skill(object me)
{
	object* ob, obj;
	int i,skill,damage,cost;
	cost=40;
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必須空手才能練習。\n");
	if ((int)me->query("qi") < 160)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的內力不夠練六脈神劍。\n");
	if( skill > 100 && me->query("shen") < 1)
		return notify_fail("這種武功當得行俠義事。\n");
	if ((int)me->query_skill("six-finger", 1)>150) cost=80;
	if ((int)me->query_skill("six-finger", 1)>250) cost=160;
	me->receive_damage("qi", cost);
	me->add("neili", -30);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/2) > victim->query_str() )
	{
		victim->receive_wound("qi", (damage_bonus - 100) / 3 );
		return HIR "你聽到「嗤啦」一聲輕響，臉上竟濺到一些血滴！\n" NOR;
	}
}
mapping query_action(object me, object weapon)
{
	int d_e1 = 25;
	int d_e2 = 5;
	int p_e1 = -30;
	int p_e2 = -50;
	int f_e1 = 500;
	int f_e2 = 600;
	int i, lvl, seq, ttl = sizeof(action);

	if (random(me->query_skill("six-finger",1)) > 60 &&
		me->query_skill("kurong-changong",1) > 60 &&
		me->query("neili") > 100)
	{
		me->add("neili",-50);
		return ([
			"action" : "$N忽然覺得劍譜中的六路劍法一一湧向心頭，十指紛彈，此去彼來，連綿無盡。劍氣縱橫，塵煙四起，六路劍法迴轉運使，$n頓時心神大亂，但覺全身幾處刺痛，幾股鮮血從身上標出。忍痛抬頭一看，一柱劍氣迎面又到",
			"dodge": 5,
			"parry": -50,
			"force": 600,
			"damage_type": "刺傷"]);
	}
	else
	{
		lvl = (int)me->query_skill("six-finger", 1);
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
			"damage_type" : random(2) ? "內傷" : "刺傷",
		]);
	}
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"six-finger/" + action;
}
int help(object me)
{
	write(HIC"\n六脈神劍："NOR"\n");
	write(@HELP

    六脈神劍是大理段氏不傳之祕。天龍寺為大理武學之根本，此
技即為天龍鎮寺之寶，俗家弟子無法窺其堂奧。六脈神劍並非普通
劍法，而是以無上內力運指作劍，傷敵於無形，亦即“氣劍”。

	學習要求：
		枯榮禪功120級
		內力1200
HELP
	);
	return 1;
}


