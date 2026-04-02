// lingboweibu.c 凌波微步
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }
#include <xiaoyao.h>

string *dodge_msg = ({
	"$n輕輕巧巧地往前一步，衣袂飄忽，一式"HIW"「輕雲蔽月」"NOR"身影恍惚如浮雲，\n$N只覺眼花繚亂。\n",
	"$n袍袖輕拂，拔地而起，在空中轉了一圈，一式"HIW"「流風迴雪」"NOR"有如漫天\n瓊花飛舞，$N目眩神迷，辨不清方向。\n",
	"$n抬手掩面，嫣然一笑，左一步，右二步，斜刺裏又三步，一式"MAG"「羅襪生塵」"NOR"\n輕捷婀娜，只見地上纖塵紛揚，$N呆立半晌，渾忘了如何出招。\n",
	"$n待$N攻近面門，突然身形後仰，後退幾步，一式"MAG"「輕裾曳霧」"NOR"施施然\n躲過了$N這一招。\n",
	"$n一式"HIM"「驚鴻回眸」"NOR"，一個側身飄然掠起，轉眼已在$N身後。\n",
	"$n舒展身體，抖擻精神，一式"HIY"「遊龍翩飛」"NOR"迅捷如電，側身讓過了$N這招。\n",
	"$n回眸粲然，一式"HIG"「清流弄履」"NOR"有如流水濺濕文履，剎那間滑出丈餘許，\n$N這一招撲了個空。\n",
	"$n泰然自若，左足上挑，右足力蹬，一式"HIG"「神渚濯足」"NOR"縱躍於幾丈開外。\n",
	"$n氣定神閒，籠袖不動，足下卻是風生水起，一式"HIB"「屏翳收風」"NOR"飄然避過\n$N這招。\n",
	"$n身形將傾未傾，若往若還，一式"HIC"「川后靜波」"NOR"如微風輕掠水面，倏忽已\n不見人影。\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("beiming-shengong", 1) < 10 )
	return notify_fail("你的北冥神功不夠精熟，無法領會凌波微步。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 10 )
		return notify_fail("你的體力太差了，無法練習凌波微步。\n");
	me->receive_damage("qi", 50);
	me->add("neili", -10);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"lingboweibu/" + action;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { 
	if (fam_type(me)=="xiaoyao")	return 1.5;
	return 1.0;
}

int help(object me)
{
	write(HIC"\n凌波微步："NOR"\n");
	write(@HELP

    洛神賦：“凌波微步，羅襪生塵……轉盼流精，光潤玉顏。含
辭未吐，氣若幽蘭。華容婀娜，令我忘餐。［禾農］纖得衷，修短
合度，肩若削成，腰如紅素，延頸秀項，皓質呈露，芳澤無加，鉛
華弗御。雲髻峨峨，修眉連娟。丹脣外朗，皓齒內鮮。明眸善睞，
輔薜承權。環姿豔逸，儀靜體閒。柔情綽態，媚於語言……皎若太
陽升朝霞，灼若芙蓉出綠波”。
    凌波微步原載於北冥神功帛卷卷末，按伏羲六十四卦而排，內
勁行遍一周天，腳步亦踏遍六十四卦一周天。步法輕靈迅捷，有如
凌波而行，羅襪生塵，巧妙已極。
    凌波微步乃逃命之妙法，非害人之本領也，練之有百利而無一
害。

	學習要求：
	  北冥神功10級
HELP
	);
	return 1;
}

