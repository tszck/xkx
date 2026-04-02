// anran-zhang.c
// Last Modified by sir 10.21.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action=({
([	"action":"$N抬頭向天，渾若不見，呼的一掌向自己頭頂空空拍出，手掌斜下，掌力化成弧形，四散落下。這一式"HIB"「杞人憂天」"NOR"力似穹廬，圓轉廣被，$n實是無可躲閃",
	"skill_name":"杞人憂天",
	"lvl":0
]),
([	"action":"$N手臂下垂，絕無半點防禦姿式，待得$n攻到近肉寸許，突然間手足齊動，左掌右袖、雙足頭錘，一招"HIB"「無中生有」"NOR"連帶胸背腰腹盡同時出招，無一不足傷敵",
	"skill_name":"無中生有",
	"lvl":10
]),
([	"action":"$N右手雲袖飄動，宛若流水，左掌卻重滯之極，便似帶着幾千斤泥沙一般。右袖是北方癸水之路，左掌是中央戊土之家，一式"HIB"「拖泥帶水」"NOR"輕靈沉猛，兼而有之",
	"skill_name":"拖泥帶水",
	"lvl":20
]),
([	"action": "$N緩步向前，瞅準$n出招空隙，無聲無息發出一掌，正是"HIB"「徘徊空谷」"NOR"。",
	"skill_name":"徘徊空谷",	
	"lvl":30
]),
([	"action":"$N退後幾步，似乎久戰疲倦，力有不逮，等到$n趨近身前，“呼”地一
掌，一式"HIB"「力不從心」"NOR"劈向$n",
	"skill_name":"力不從心",
	"lvl":40
]),
([	"action":"$N退步避開，踢出一腳，使出一招"HIB"「行屍走肉」"NOR"，這一腳發出時恍恍
惚惚，隱隱約約，若有若無，踢向$n胸口",
	"skill_name":"行屍走肉",
	"lvl":60
]),
([	"action":"$N突然高高躍起，一招"HIB"「倒行逆施」"NOR"頭下腳上，倒過身子，拍出一掌",
	"skill_name":"倒行逆施",
	"lvl":70
]),
([	"action":"$N收掌不動，待$n出招將至未至之際，眼中精光四射，肘彎一沉，突地
發出一掌，正是一招"HIB"「廢寢忘食」"NOR"。",
	"skill_name":"廢寢忘食",
	"lvl":80
]),
([	"action":"$N煢煢鵠立，傲然望天，待$n襲至身畔，凝然拍出一掌，一招"HIB "「孤形隻影」"NOR"揮向$n肩背",
	"skill_name":"孤形隻影",
	"lvl":100
]),
([	"action":"只見$N身形飄忽，神情悵然，猛地一式"HIB"「飲恨吞聲」"NOR"，重重拍向$n身上",
	"skill_name":"飲恨吞聲",
	"lvl":110
]),
([	"action":"$N身形晃動，長袖飄動，左掌飛揚，使出一招"HIB"「六神不安」"NOR"，將$n裹
在掌風之中",
	"skill_name":"六神不安",
	"lvl":120
]),
([	"action":"$N長嘆一聲，負手踽踽而行，渾然不理$n的攻擊，直至最後一刻，驀然
長聲冷笑，轉身就是一式"HIB"「窮途末路」"NOR"。",
	"skill_name":"窮途末路",
	"lvl":140
]),
([	"action":"$N一聲清嘶，一式"HIB"「心驚肉跳」"NOR"，掌風如電，霎時間似乎千軍萬馬一
齊殺到，將$n罩在掌影中",
	"skill_name":"心驚肉跳",
	"lvl":150
]),
([	"action":"$N臉上喜怒哀樂，怪狀百出，$n一見，登時心神難以自制，呆立在$N
面前，$N見機“呼”地一掌"HIB"「面無人色」"NOR"拍向$n胸口",
	"skill_name":"面無人色",
	"lvl":160
]),
([	"action":"$N若有所思，自顧自疾步衝向$n，突然發招，一式"HIB"「想入非非」"NOR"出手如
電，扣向$n手腕，掌風兀自不歇，猛擊$n小腹",
	"skill_name":"想入非非",
	"lvl":170
]),
([	"action":"$N呆立不動，悵然若失，催動內力硬生生抵住$n的一記重招，趁$n未及
撤招，驀然一式"HIB"「呆若木雞」"NOR"攻出，全身勁力傾注掌中",
	"skill_name":"呆若木雞",
	"lvl":180
]),
([	"action":"$N面色慘白，雙目無光，萬念俱灰，沒精打採地揮袖卷出，拍出一掌，
正是一招"HIB"「魂不守舍」"NOR"。",
	"skill_name":"魂不守舍",
	"lvl":200
]),
});

int valid_enable(string usage) {return usage=="unarmed" || usage=="parry";}

int valid_learn(object me)
{
	mapping myfam;
	myfam = (mapping)me->query("family");
	if(myfam["master_id"]!="yang guo")
		return notify_fail("你只能向楊過學這門武功。\n");
	if ((int)me->query("max_neili") < 1500)
		return notify_fail("你的內力太弱，無法練黯然銷魂掌。\n");
	if ((int)me->query_skill("yunv-xinfa", 1) < 100)
		return notify_fail("你的玉女心法不熟練，無法練黯然銷魂掌。\n");
/*
	if((me->query("normal_die")<10)&&(time()-me->query("dietime")>300))
		return notify_fail("你沒有能體會這門武功的心境。\n");
*/
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練黯然銷魂掌必須空手。\n");
	return 1;
}
int practice_skill(object me)
{	
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必須空手才能練習。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的內力不夠練黯然銷魂掌。\n");
	me->receive_damage("qi", 30);
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
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 10;
	int d_e2 = 30;
	int p_e1 = -45;
	int p_e2 = 25;
	int f_e1 = 300;
	int f_e2 = 400;	
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("anran-zhang", 1);
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
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }
string perform_action_file(string action)
{
	return __DIR__"anran-zhang/" + action;
}
int help(object me)
{
	write(HIC"\n黯然銷魂掌："NOR"\n");
	write(@HELP

    楊過自和小龍女在絕情谷斷腸崖前分手，不久便由神鵰帶着在
海潮之中練功，數年之後，除了內功循序漸進之外，別的無可再練，
心中整日價思念小龍女，漸漸的形銷骨立，了無生趣。一日在海濱
悄然良久，百無聊賴之中隨意拳打腳踢，其時他內功火候已到，一
出手竟具極大威力，輕輕一掌，將海灘上一隻大海龜的背殼打得粉
碎。他由此深思，創出了一套完整的掌法，出手與尋常武功大異，
厲害之處，全在內力，一共是一十七招。
    楊過生平受過不少武學名家的指點，自全真教學得玄門正宗內
功的口訣，自小龍女學得【玉女心經】，在古墓中見到【九陰真經
】，歐陽鋒以蛤蟆功和逆轉經脈，洪七公與黃蓉授以打狗棒法，黃
藥師授以彈指神通和玉簫劍法，除了一陽指之外，東邪、西毒、北
丐、中神通的武學無所不窺，而古墓派的武學又於五大高人之外別
創蹊徑，他依此融會貫通，卓然成家，創立此掌法。只因他單剩一
臂，是以不在招數變化取勝，反而故意與武學通理相反。將這套掌
法定名爲“黯然銷魂掌”，取的是江淹【別賦】中那一句“黯然銷
魂者，唯別而已矣”之意。實飽含對小龍女的刻骨思念之情。

	學習要求：
		玉女心法100級
		內力1500
		只能向楊過學習
HELP
	);
	return 1;
}

