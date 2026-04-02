// taiji-quan.c 太極拳
// Last Modified by sir 10.21.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *taijin = ({ "「陰陽訣」", "「動靜訣」", "「兩儀訣」", "「剛柔訣」", "「沾黏訣」",  "「引字訣」","鑽翻", "螺旋","靜恆","開合","軟手","虛靈"});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *parry_msg = ({
	 "$p眼見$P$w攻到，當即使出一招「攬雀尾」，右腳實，左腳虛，運起“擠”字訣，粘連粘隨，右掌已搭住$P左腕，橫勁發出。$N身不由主的向前一衝，跨出兩步，方始站定。\n",
	 "不料$p雙手一圈，如抱太極，一股雄渾無比的力道組成了一個旋渦，只帶得$P在原地急轉七八下。\n",
	 "$p「雙風貫耳」，連消帶打，雙手成圓形擊出，隨即左圈右圈，一個圓圈跟着一個圓圈，大圈、小圈、平圈、立圈、正圈、斜圈，一個個太極圓圈發出，登時便套得$P跌跌撞撞，身不由主的立足不穩。\n",
	 "$p使出一招「雲手」，左手高，右手低，一個圓圈已將$P$w套住。\n",
	 "$p覺氣息微窒，當下一招「斜飛勢」，將$P$w引偏。\n",
	 "$p吸一口氣，體內真氣流轉，右掌揮出，一拒一迎，將$P的力道盡行碰了回去。\n",
	 "$p雙掌一翻，使出一招「雲手」，雙掌柔到了極處，空明若虛，將$P$w的急勁盡數化去。\n",
	"$p當即雙掌一揚，迎着$w接去，待得手掌與$P$w將觸未觸之際，施出「攬雀尾式」，將$w輕輕攏住，腳下“金雞獨立式”，左足關地，右足懸空，全身急轉，宛似一枚陀螺。\n",
	 "就在這電光石火的一瞬之間，$p身子一弓，正是「白鶴亮翅」的前半招，$P的勁力登時落空。\n",
});

mapping *action = ({
([	"action" : "$N使一招"+(order[random(13)])+"「攬雀尾」"NOR"，雙手劃了個半圈，按向$n的$l",	
	"skill_name" : "攬雀尾",
	"lvl" : 0
]),
([	"action" : "$N使一招"+(order[random(13)])+"「單鞭」"NOR"，右手收置肋下，左手向外揮出，劈向$n的$l",
	"skill_name" : "單鞭",
	"lvl" : 5
]),
([	"action" : "$N左手回收，右手由鉤變掌，由右向左，使一招"+(order[random(13)])+"「提手上式」"NOR"，向$n的$l打去",
	"skill_name" : "提手上式",
	"lvl" : 10
]),
([	"action" : "$N雙手劃弧，右手向上，左手向下，使一招"+(order[random(13)])+"「白鶴亮翅」"NOR"，分擊$n的面門和$l",
	"skill_name" : "白鶴亮翅",
	"lvl" : 15
]),
([	"action" : "$N左手由胸前向下，身體微轉，劃了一個大圈，使一招"+(order[random(13)])+"「摟膝拗步」"NOR"，擊向$n的$l",
	"skill_name" : "摟膝拗步",
	"lvl" : 20
]),
([	"action" : "$N左手由下上挑，右手內合，使一招"+(order[random(13)])+"「手揮琵琶」"NOR"，向$n的$l打去",
	"skill_name" : "手揮琵琶",
	"lvl" : 25
]),
([	"action" : "$N左手變掌橫於胸前，右拳由肘下穿出，一招"+(order[random(13)])+"「肘底看錘」"NOR"，錘向$n的$l",
	"skill_name" : "肘底看錘",
	"lvl" : 30
]),
([	"action" : "$N左腳前踏半步，右手使一招"+(order[random(13)])+"「海底針」"NOR"，指由下向$n的$l戳去",
	"skill_name" : "海底針",
	"lvl" : 35
]),
([	"action" : "$N招"+(order[random(13)])+"「閃通臂」"NOR"，左腳一個弓箭步，右手上舉向外撇出，向$n的$l揮去",
	"skill_name" : "閃通臂",
	"lvl" : 40
]),
([	"action" : "$N兩手由相對，轉而向左上右下分別揮出，右手使一招"+(order[random(13)])+"「斜飛式」"NOR"，揮向$n的$l",
	"skill_name" : "斜飛式",
	"lvl" : 45
]),
([	"action" : "$N左手虛按，右手使一招"+(order[random(13)])+"「白蛇吐信」"NOR"，向$n的$l插去",
	"skill_name" : "白蛇吐信",
	"lvl" : 50
]),
([	"action" : "$N雙手握拳，向前向後劃弧，一招"+(order[random(13)])+"「雙峯貫耳」"NOR"打向$n的$l",
	"skill_name" : "雙風貫耳",
	"lvl" : 55
]),
([	"action" : "$N左手虛劃，右手一記"+(order[random(13)])+"「指襠錘」"NOR"擊向$n的襠部",
	"skill_name" : "指襠錘",
	"lvl" : 60
]),
([	"action" : "$N施出"+(order[random(13)])+"「伏虎式」"NOR"，右手擊向$n的$l，左手攻向$n的襠部",
	"skill_name" : "伏虎式",
	"lvl" : 65
]),
([	"action" : "$N由臂帶手，在面前緩緩劃過，使一招"+(order[random(13)])+"「雲手」"NOR"，揮向$n的$l",
	"skill_name" : "雲手",
	"lvl" : 70
]),
([	"action" : "$N左腿收起，右手使一招"+(order[random(13)])+"「金雞獨立」"NOR"，向$n的$l擊去",
	"skill_name" : "金雞獨立",
	"lvl" : 75
]),
([	"action" : "$N右手由鉤變掌，雙手掌心向上，右掌向前推出一招"+(order[random(13)])+"「高探馬」"NOR"",
	"skill_name" : "高探馬",
	"lvl" : 80
]),
([	"action" : "$N右手使一式招"+(order[random(13)])+"「玉女穿梭」"NOR"，撲身向$n的$l插去",
	"skill_name" : "玉女穿梭",
	"lvl" : 85
]),
([	"action" : "$N右手經腹前經左肋向前撇出，使一招"+(order[random(13)])+"「反身撇錘」"NOR"，向$n的$l錘去",
	"skill_name" : "反身撇錘",
	"lvl" : 90
]),
([	"action" : "$N左手虛按，右腿使一招"+(order[random(13)])+"「轉身蹬腿」"NOR"，向$n的$l踢去",
	"skill_name" : "反身蹬腿",
	"lvl" : 95
]),
([	"action" : "$N左手向上劃弧攔出，右手使一招"+(order[random(13)])+"「搬攔錘」"NOR"，向$n的$l錘去",
	"skill_name" : "白蛇吐信",
	"lvl" : 100
]),
([	"action" : "$N使一招"+(order[random(13)])+"「栽錘」"NOR"，左手摟左膝，右手向下錘向$n的$l",
	"skill_name" : "栽錘",
	"lvl" : 120
]),
([	"action" : "$N雙手先抱成球狀，忽地分開右手上左手下，一招"+(order[random(13)])+"「野馬分鬃」"NOR"，向$n的$l和麪門打去",
	"skill_name" : "野馬分鬃",
	"lvl" : 150
]),
([	"action" : "$N左手由胸前向下，右臂微曲，使一招"+(order[random(13)])+"「抱虎歸山」"NOR"，向$n的$l推去",
	"skill_name" : "抱虎歸山",
	"lvl" : 180
]),
([	"action" : "$N雙手經下腹劃弧交於胸前，成十字狀，一式"+(order[random(13)])+"「十字手」"NOR"，向$n的$l打去",
	"skill_name" : "十字手",
	"lvl" : 210
]),
([	"action" : "$N左腳踏一個虛步，雙手交叉成十字拳，一招"+(order[random(13)])+"「進步七星」"NOR"，向$n的$l錘去",
	"skill_name" : "進步七星",
	"lvl" : 240
]),
([	"action" : "$N身體向後騰出，左手略直，右臂微曲，使一招"+(order[random(13)])+"「倒攆猴」"NOR"，向$n的$l和麪門打去",
	"skill_name" : "倒攆猴",
	"lvl" : 270
]),
([	"action" : "$N雙手伸開，以腰爲軸，整個上身劃出一個大圓弧，\n一招"+(order[random(13)])+"「轉身擺蓮」"NOR"，將$n渾身上下都籠罩在重重掌影之中",
	"skill_name" : "轉身擺蓮",
	"lvl" : 300
]),
([	"action" : "$N雙手握拳，右手緩緩收至耳際，左手緩緩向前推出，\n拳意如箭，一招"+(order[random(13)])+"「彎弓射虎」"NOR"，直奔$n心窩而去",
	"skill_name" : "彎弓射虎",
	"lvl" : 400
]),
([	"action" : "$N雙手在胸前翻掌，由腹部向前向上推出，一招"+(order[random(13)])+"「如封似閉」"NOR"，一股勁風直逼$n",
	"skill_name" : "如封似閉",
	"lvl" : 500
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練太極拳必須空手。\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 20)
		return notify_fail("你的太極神功火候不夠，無法學太極拳。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的內力太弱，無法練太極拳。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必須空手才能練習。\n");
	if ((int)me->query("qi") < 70)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 70)
		return notify_fail("你的內力不夠練太極拳。\n");
	me->receive_damage("qi", 60);
	me->add("neili", -60);
	return 1;
}
string query_parry_msg(string limb)
{
	return parry_msg[random(sizeof(parry_msg))];
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
	int d_e1 = 0;
	int d_e2 = 20;
	int p_e1 = -50;
	int p_e2 = 30;
	int f_e1 = 400;
	int f_e2 = 600;	
	int i, lvl, seq, ttl = sizeof(action);
	string msg;
	lvl = (int) me->query_skill("taiji-quan", 1);
/////////yun taiji/////////	
	if( me->query_temp("taiji") && me->query("neili") > 100 )
	{
 		      me->add_temp("taiji_fight", 1);
msg = random(2)==1?
HIW"只見$N虛靈頂勁、涵胸拔背、松腰垂臀、沉肩墜肘，雙手抱了個太極式的圓圈，純以意行太極，\n已達形神合一，心動氣動的境界，結果使出了太極拳中的"NOR:
HIW"剎時間$N悟到了太極拳旨中“似松非松，將展未展，勁斷意不斷”的精微奧妙之處，\n使出一招猶如行雲流水，瀟灑無比。結果使出了太極拳中的"NOR;
msg = msg + order[random(sizeof(order))] + taijin[random(sizeof(taijin))] + NOR;
        if ( lvl > 250 
        && random(lvl) > 200
        && random(10)>5)
        {
	      	me->add("neili", -10);
        	return ([  
                	"action" : msg,
                	"force" :  600,
                	"dodge":   -80,
               // 	"damage":   500,
                	"parry":   -80,
                	"damage_type" : random(2)==1?"瘀傷":"內傷",
        	]);
        }
  }
  //////普通出招////////
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

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"taiji-quan/" + action;
}

int help(object me)
{
	write(WHT"\n太極拳："NOR"\n");
	write(@HELP

    太極拳，爲宋末元初武當張三豐真人所創，合道家之說，沖虛
自然，講究以柔克剛、四兩撥千斤。主以慢打快，以靜制動，後發
制人，無爲至虛之念的上乘武學。拳出時雙手圓轉，每一招都含着
太極式的陰陽變化，精微奧妙，實是開闢了武學中從所未有的新天
地。訣竅爲「虛靈頂勁、涵胸拔背、松腰垂臀、沉肩墜肘」十六個
字，純以意行，最忌用力。形神合一，是這路拳法的要旨。
    太極拳勁首要在似松非松，將展未展，勁斷意不斷，其接力打
力爲武林一絕。

	學習要求：
		太極神功20級
		內力100
HELP
	);
	return 1;
}

