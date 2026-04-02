// meinv-quan.c 美女拳
// Last Modified by sir 10.21.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N使一招"RED"「紅玉擊鼓」 "NOR"，雙臂交互快擊",
	"lvl" : 0,
	"skill_name" : "紅玉擊鼓"
]),
([	"action" : "$N突然變為"RED"「紅拂夜奔」"NOR"，出其不意的叩關直入，令$n大喫一驚",
	"lvl" : 10,
	"skill_name" : "紅拂夜奔"
]),
([	"action" : "$N招式一變成"GRN"「綠珠墜樓」"NOR"，撲地攻敵下盤，委實難測",
	"lvl" : 20,
	"skill_name" : "綠珠墜樓"
]),
([	"action" : "$N雙掌連拍數下，接著連綿不斷拍出，原來是"HIW"「文姬歸漢」"NOR"，共胡笳十八拍",
	"lvl" : 30,
	"skill_name" : "文姬歸漢"
]),
([	"action" : "$N使出"RED"「紅線盜盒」"NOR"，以空手入白刃之技向$n手中兵刃奪去",
	"lvl" : 40,
	"skill_name" : "紅線盜盒"
]),
([	"action" : "$N一式"HIB"「木蘭彎弓」"NOR"，左手如抱滿月，右手疾揮而過，令$n目瞪口呆",
	"lvl" : 60,
	"skill_name" : "木蘭彎弓"
]),
([	"action" : "$N忽然昂首如吟明月，雙掌從不可思議的角度攻了過來，原來是一招
"HIC"「班姬賦詩」"NOR"。",
	"lvl" : 70,
	"skill_name" : "班姬賦詩"
]),
([	"action" : "$N使招"HIC"「蠻腰纖纖」"NOR"，腰肢輕擺避開，緊跟着揮掌攻擊$n的前胸",
	"lvl" : 80,
	"skill_name" : "蠻腰纖纖"
]),
([	"action" : "$N五指在自己頭髮上一梳，跟著軟軟的揮了出去，臉上微微一笑，卻
是一招"HIW"「麗華梳裝」"NOR"。",
	"lvl" : 90,
	"skill_name" : "麗華梳裝"
]),
([	"action" : "$N見$n呆住，伸指戳出，卻是一招"HIM"「萍姬針神」"NOR"。",
	"lvl" : 110,
	"skill_name" : "萍姬針神"
]),
([	"action" : "$N突然間蹙起眉頭，宛如"MAG"「西子捧心」"NOR"，雙掌自自己胸口攻出",
	"lvl" : 130,
	"skill_name" : "西子捧心"
]),
([	"action" : "$N腳下翩若驚鴉、矯若遊龍，猶如在水上漂行一般，卻是一招"HIW "「洛神微步」"NOR"。",
	"lvl" : 150,
	"skill_name" : "洛神微步"
]),
([	"action" : "$N使招"HIM"「曹令割鼻」"NOR"，揮手在自己臉上斜削一掌，左掌削過，右掌又削，連綿不斷",
	"lvl" : 180,
	"skill_name" : "曹令割鼻"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練美女拳必須空手。\n");
	if ((int)me->query_skill("yunv-xinfa", 1) < 10)
		return notify_fail("你的玉女心法火候不夠，無法學美女拳。\n");
	if ((int)me->query("max_neili") < 30)
		return notify_fail("你的內力太弱，無法學習美女拳。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必須空手才能練習。\n");
	if( (int)me->query("qi") < 70 || (int)me->query("neili") < 70 )
		return notify_fail("你的體力太差了，不能練習美女拳。\n");
	me->receive_damage("qi", 40);
	me->add("neili", -30);
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
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 20;
	int d_e2 = 40;
	int p_e1 = -35;
	int p_e2 = 15;
	int f_e1 = 200;
	int f_e2 = 300;	
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("meinv-quan", 1);
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

int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"meinv-quan/" + action;
}
int help(object me)
{
	write(HIC"\n美女拳："NOR"\n");
	write(@HELP

    古墓獨門武功，奇妙又花巧，拳法的每一招都是模擬一位古代
美女，將千百年來美女變幻莫測的心情神態盡數融入武術之中，婀
娜嫵媚、端麗縹緲盡皆有之，人所難測。
    古墓派自林朝英開派，從來傳女不傳男。這套「美女拳法」，
使出來時嬌媚婀娜，卻也均是凌厲狠辣的殺手。


	學習要求：
		玉女心法10級
		內力30
HELP
	);
	return 1;
}

