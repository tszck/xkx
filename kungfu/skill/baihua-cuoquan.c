// Last Modified by winder on Sep. 12 2001
// baihuacuo-quan.c 百花錯拳

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N振臂一掠，使一招"HIC"「鬥轉星移」"NOR"，雙手自兩側擊向$n",
	"skill_name" : "鬥轉星移",
	"lvl" : 0
]),
([	"action" : "$N使一招"HIW"「橫雲斷峯」"NOR"，左手成掌，護住前胸，右手成拳，打向$n的$l",
	"skill_name" : "橫雲斷峯",
	"lvl" : 5
]),
([	"action" : "$N左手伸出，右手緊握，使一招"GRN"「分花拂柳」"NOR"，直進中宮，向$n的$l打去",
	"skill_name" : "分花拂柳",
	"lvl" : 10
]),
([	"action" : "$N雙手一併，右手用剛，左手用柔，使一招"RED"「顛倒陰陽」"NOR"，分擊$n的前胸和$l",
	"skill_name" : "顛倒陰陽",
	"lvl" : 15
]),
([	"action" : "$N雙手雙外推出，身體滴溜溜一轉，劃了一個大圈，使一招"BLU"「夜戰八方」"NOR"，擊向$n的$l",
	"skill_name" : "夜戰八方",
	"lvl" : 20
]),
([	"action" : "$N一躍上前，使一招"MAG"「風虎雲龍」"NOR"，右拳奮力向$n的$l打去",
	"skill_name" : "風虎雲龍",
	"lvl" : 25
]),
([	"action" : "$N拳掌一分，斜身上步，一招"HIG"「穿花繞樹」"NOR"，錘向$n的$l",
	"skill_name" : "穿花繞樹",
	"lvl" : 30
]),
([	"action" : "$N左腳前踏半步，右手使一招"HIY"「倒打金鐘」"NOR"，指由下向$n的$l戳去",
	"skill_name" : "倒打金鐘",
	"lvl" : 35
]),
([	"action" : "$N一招"YEL"「指天劃地」"NOR"，小臂劃了半個圓弧，雙掌緩緩向外推出，向$n的$l揮去",
	"skill_name" : "指天劃地",
	"lvl" : 40
]),
([	"action" : "$N左手橫擋，右掌一揮，右手使一招"GRN"「燕子斜飛」"NOR"，揮向$n的$l",
	"skill_name" : "燕子斜飛",
	"lvl" : 45
]),
([	"action" : "$N左手虛攻，右手緊並,使一招"HIR"「移花接木」"NOR"，向$n的$l插去",
	"skill_name" : "移花接木",
	"lvl" : 50
]),
([	"action" : "$N趁勢前撲，一招"HIM"「魁星踢鬥」"NOR"拳中夾腿打向$n的$l",
	"skill_name" : "魁星踢鬥",
	"lvl" : 55
]),
([	"action" : "$N左手在$n面門一晃，右手一記"HIW"「雲橫秦嶺」"NOR"擊向$n的$l",
	"skill_name" : "雲橫秦嶺",
	"lvl" : 60
]),
([	"action" : "$N施出"MAG"「月移花影」"NOR"，身形不住閃動，雙手同時攻向$n的$l",
	"skill_name" : "月移花影",
	"lvl" : 65
]),
([	"action" : "$N穩紮馬步，吐氣開聲，"HIY"「中流砥柱」"NOR"，雙拳錘向$n的$l",
	"skill_name" : "中流砥柱",
	"lvl" : 70
]),
});
int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="benlei-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練百花錯拳必須空手。\n");
	if ((int)me->query_skill("honghua-shengong", 1) < 20)
		return notify_fail("你的紅花神功火候不夠，無法學百花錯拳。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的內力太弱，無法練百花錯拳。\n");
	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的內力不夠練百花錯拳。\n");
	me->receive_damage("qi", 35);
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
	int d_e1 = 25;
	int d_e2 = 50;
	int p_e1 = -30;
	int p_e2 = -15;
	int f_e1 = 130;
	int f_e2 = 280;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("baihua-cuoquan", 1);
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
		"damage_type" : "瘀傷",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point() { return 1.0; }
string perform_action_file(string action)
{
	return __DIR__"baihua-cuoquan/" + action;
}

int help(object me)
{
	write(HIM"\n百花錯拳："NOR"\n");
	write(@HELP

    百花錯拳是天池怪俠袁士霄所創。袁士霄痛悔當年錯過大好因緣，
以世上萬物多錯，創出此拳。此拳取衆家之長，往往似是而非，誘敵
入彀，故稱錯拳。
    紅花會總舵主陳家洛爲袁士霄入室弟子，得傳此拳。

	學習要求：
		紅花神功20級
		內力修爲100
HELP
	);
	return 1;
}
