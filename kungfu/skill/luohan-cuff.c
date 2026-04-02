// Last Modified by winder on May. 29 2001
// luohan-cuff.c 少林羅漢拳 與風雲手互備 截自《少林拳法》，取其一至三十式。

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([	"action" : "$N一式"+(order[random(13)])+"「抱手起式」"NOR"，身體保持站立的姿勢不變，雙眼平視前方，雙掌前探，雙手握拳，抓向$n腰間",
	"lvl"   : 0,
	"skill_name" : "抱手起式"
]),
([	"action" : "$N左腳虛踏，一招"+(order[random(13)])+"「平步栽掌」"NOR"，身體仍然保持站立的姿勢不變，左手化掌，向前直封而出",
	"lvl"   : 4,
	"skill_name" : "平步栽掌"
]),
([	"action" : "$N右腳原地跺步，左腳踏前勾出，成七星步坐定，一招"+(order[random(13)])+"「跺腳崩掛」"NOR"，右手向右橫拉而出",
	"lvl"   : 8,
	"skill_name" : "跺腳崩掛"
]),
([	"action" : "$N全身向前，一招"+(order[random(13)])+"「進步劈砸」"NOR"，右掌向前直劈而落，左掌同時翻掌硬接，自然擊出聲音",
	"lvl"   : 12,
	"skill_name" : "進步劈砸"
]),
([	"action" : "$N左掌護住右腕不動，右手原地向外翻手抓採，出"+(order[random(13)])+"「採刁出掌」"NOR"，右手不動，左掌向$n直切而出",
	"lvl"   : 16,
	"skill_name" : "採刁出掌"
]),
([	"action" : "$N右腳拖進，向下蹲成玉環步坐定，右手反拳一式"+(order[random(13)])+"「跟步擊砸」"NOR"向前劈落，左掌更翻掌而出",
	"lvl"   : 20,
	"skill_name" : "跟步擊砸"
]),
([	"action" : "$N保持玉環步姿勢坐定不動，左手扣腕，右掌上翻出"+(order[random(13)])+"「順勢採手」"NOR"，以纏絲手向$n$l採出",
	"lvl"   : 24,
	"skill_name" : "順勢採手"
]),
([	"action" : "$N的纏絲手向下採壓，身體原地向上立起"+(order[random(13)])+"「雙落蹬子」"NOR"，接着起右腿向$n直蹬而出",
	"lvl"   : 28,
	"skill_name" : "雙落蹬子"
]),
([	"action" : "$N將右腳尖回勾，以膝蓋向前直頂而出"+(order[random(13)])+"「提膝頂破」"NOR"，順勢右拳收腰，左手封掌前推",
	"lvl"   : 32,
	"skill_name" : "提膝頂破"
]),
([	"action" : "$N一招"+(order[random(13)])+"「移步截砸」"NOR"，身體微仰不動，雙掌向左同時以圈封手向前採出，接着左掌前託，右拳順勢向前低劈$n",
	"lvl"   : 36,
	"skill_name" : "移步截砸"
]),
([	"action" : "$N將左腳伸直，成弓箭步站定，一招"+(order[random(13)])+"「迎手托架」"NOR"，右手翻掌上架，左手順勢壓掌下封",
	"lvl"   : 40,
	"skill_name" : "迎手托架"
]),
([	"action" : "$N一招"+(order[random(13)])+"「採壓衝捶」"NOR"，右腳原地跺步，使身體轉正，接着左封掌下壓，右掌向前直擊$n",
	"lvl"   : 44,
	"skill_name" : "採壓衝捶"
]),
([	"action" : "$N接着"+(order[random(13)])+"「轉身攔截」"NOR"，順著身體右轉之勢，收右拳，撩左掌，雙手交叉，向$n橫劈而出",
	"lvl"   : 48,
	"skill_name" : "轉身攔截"
]),
([	"action" : "$N右腳向右踏出　使身體衝向右方，一招"+(order[random(13)])+"「進步衝捶」"NOR"，收左手扣腰，右手化掌向$n圈封而出",
	"lvl"   : 52,
	"skill_name" : "進步衝捶"
]),
([	"action" : "$N一式"+(order[random(13)])+"「回馬拉捶」"NOR"，步法左轉，成馬步坐定，左手挑回扣住腰際，右掌順勢向$n$l擊出",
	"lvl"   : 56,
	"skill_name" : "回馬拉捶"
]),
([	"action" : "$N又一招"+(order[random(13)])+"「進步衝捶」"NOR"，右手順勢向前圈採而出，步法隨著右轉之勢，左手化掌向$n直擊而出",
	"lvl"   : 60,
	"skill_name" : "進步衝捶"
]),
([	"action" : "$N使出"+(order[random(13)])+"「採刁踢」"NOR"，左手以採刁手由上向前勾落，同時，左腿以勾腿式向$n$l勾踢而出",
	"lvl"   : 64,
	"skill_name" : "採刁踢"
]),
([	"action" : "$N將身體重心移至左腳，使右腳離地蓄勁，一招"+(order[random(13)])+"「套步踢」"NOR"，右腿以勾腿式由上向前勾落",
	"lvl"   : 68,
	"skill_name" : "套步踢"
]),
([	"action" : "$N右腳向右落步，以腳尖輕點地面，一招"+(order[random(13)])+"「跨步反砸」"NOR"，左掌一直護肩不動，右掌向右反崩而出",
	"lvl"   : 72,
	"skill_name" : "跨步反砸"
]),
([	"action" : "$N雙腿順勢轉正，原地跺步，成弓箭步站定，一招"+(order[random(13)])+"「穿刁斜打」"NOR"，右手化掌，向$n$l橫切",
	"lvl"   : 76,
	"skill_name" : "穿刁斜打"
]),
([ 	"action" : "$N步法原地向下成馬步坐定，一招"+(order[random(13)])+"「低馬擊砸」"NOR"，右拳擊砸於左膝前方，左掌則翻掌硬推",
	"lvl"   : 80,
	"skill_name" : "低馬擊砸"
]),
([	"action" : "$N一招"+(order[random(13)])+"「起胳托架」"NOR"，將左腳撐直，成弓箭步站定，右拳順勢翻肘，向$n架出",
	"lvl"   : 84,
	"skill_name" : "起胳托架"
]),
([	"action" : "$N右手化掌，向前直採而出，使出"+(order[random(13)])+"「翻身攔打」"NOR"，右腳原地跺步，使身體轉向$n踢出",
	"lvl"   : 88,
	"skill_name" : "翻身攔打"
]),
([	"action" : "$N收左手，右手原地向前架採而出，右腳順勢向$n$l直踢，正是一式"+(order[random(13)])+"「進步架打」"NOR"",
	"lvl"   : 92,
	"skill_name" : "進步架打"
]),
([	"action" : "$N將重心放至右腳，使左腳放虛，一招"+(order[random(13)])+"「回步衝捶」"NOR"，向左原地轉回，膝蓋順勢抵向$n$l",
	"lvl"   : 96,
	"skill_name" : "回步衝捶"
]),
([	"action" : "$N左掌向前直撐，封住底盤，一式"+(order[random(13)])+"「託按側蹬」"NOR"，右腿轉身以反蹬腿向$n蹬出",
	"lvl"   : 100,
	"skill_name" : "託按側蹬"
]),
([	"action" : "$N一招"+(order[random(13)])+"「採刁撐腿」"NOR"，左掌護住右腕不動，右手原地向外翻手抓採，接著左腳前踢$n",
	"lvl"   : 104,
	"skill_name" : "採刁撐腿"
]),
([	"action" : "$N左掌原地迴圈，向前封出，一招"+(order[random(13)])+"「扭步挾肘」"NOR"，右腳猛然拖進，向$n下盤猛踢三腳",
	"lvl"   : 108,
	"skill_name" : "扭步挾肘"
]),
([	"action" : "$N雙手化十字手，交叉於胸前，使出"+(order[random(13)])+"「並步迎抄」"NOR"，雙腿一躍，並踢$n$l",
	"lvl"   : 112,
	"skill_name" : "並步迎抄"
]),
([	"action" : "$N跟着又是一招"+(order[random(13)])+"「並步迎抄」"NOR"，十字手順勢向上雙抄後，雙腿凌空再次踢向$n",
	"lvl"   : 120,
	"skill_name" : "並步迎抄"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="fengyun-hand";}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練少林羅漢拳必須空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 10)
		return notify_fail("你的站樁功火候不夠，無法學少林羅漢拳。\n");
	if ((int)me->query_skill("shaolin-cuff", 1) < 10)
		return notify_fail("你的少林南拳火候不夠，無法學少林羅漢拳。\n");
	if ((int)me->query("max_neili") < 10)
		return notify_fail("你的內力太弱，無法練少林羅漢拳。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("你的體力太低，不夠練少林羅漢拳。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的內力不夠練少林羅漢拳。\n");
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
	int d_e1 = 30;
	int d_e2 = 50;
	int p_e1 = -30;
	int p_e2 = -10;
	int f_e1 = 120;
	int f_e2 = 270;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("luohan-cuff", 1);
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
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n羅漢拳："NOR"\n");
	write(@HELP

    羅漢拳爲少林拳法。與風雲手互備。

	學習要求：
		站樁功10級
		少林南拳10級
		內力修爲10。
HELP
	);
	return 1;
}

