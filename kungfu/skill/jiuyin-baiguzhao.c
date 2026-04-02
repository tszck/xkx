//jiuyin-baiguzhao.c 九陰白骨爪
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N勢若瘋虎，形若邪魔，雙爪如鋼抓鐵鈎，左手手腕翻處，右手疾伸，五根手指抓向$n$l",
]),
([	"action" : "突然人影閃動，$N迫到$n身後，袖中伸出手，五根手指向$n$l插了下去",
]),
([	"action" : "$N手臂關節喀喇一響，手臂斗然長了半尺，一掌按在$n$l，五指即要插進",
]),
([	"action" : "$N雙手微張，十根尖尖的指甲映出灰白光芒，突然翻腕出爪，五指猛地插落",
]),
([	"action" : "$N左手突然在$n眼前上圍下鈎，左旋右轉，連變了七八般，驀地裏右手一伸，五根手指直插$n$l",
]),
([	"action" : "$N雙掌不住地忽伸忽縮，手臂關節喀喇聲響，右掌一立，左掌啪的一下朝$n$l擊去",
]),
([	"action" : "$N身形挫動，風聲虎虎，接着朝$n連發八掌，一掌快似一掌，一掌猛似一掌",
]),
([	"action" : "$N攸地變爪為掌，身子不動，右臂陡長，潛運內力，一掌朝$n$l劈去",
]),
([	"action" : "$N一聲怪嘯，形如飄風，左掌已如風行電摯般拍向$n，掌未到，風先至，迅猛已極",
]),
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練九陰白骨爪必須空手。\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的內力太弱，無法練九陰白骨爪。\n");
	return 1;
}
int practice_skill(object me)
{
	object* ob, obj;
	int i,skill,damage,cost;

	cost = 40;
	skill = me->query_skill("jiuyin-baiguzhao",1);
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必須空手才能練習。\n");
	if ((int)me->query("qi") < 120)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的內力不夠練九陰白骨爪。\n");
	if( environment(me)->query("no_fight") )
		return notify_fail("這裏練功會誤傷他人。\n");
	if( environment(me)->query("sleep_room") )
		return notify_fail("這裏練功會打擾別人休息。\n");
	if( !objectp(obj=present("corpse", environment(me))))
		return notify_fail("練九陰白骨抓需有屍體。\n");
	if( skill > 100 && me->query("shen") > -100)
		return notify_fail("這種邪惡武功不是俠義道當練的。\n");
	if (skill > 150) cost = 80;
	if (skill >= 250) cost = 120;
	me->receive_damage("qi", cost);
	me->add("neili", -40);
//	tell_room(environment(me), 
  message_vision(
HIB"只見$N左手上圈下鈎、左旋右轉，連變了七八般花樣，驀地裏右手一伸，噗的
一響，五根手指直插入地上屍體的腦門。隨後五根手指"HIR"血淋淋"HIB"的提將起來。\n"NOR,me);
/*
	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++)
	{
		if( !living(ob[i]) || ob[i]->query_temp("noliving") ||
			ob[i]==me ) continue;
		if(skill+random(skill/2)<(int)ob[i]->query("con")*2) continue;
		damage = skill - ((int)ob[i]->query("neili") );
		if( damage > 0 )
		{
			ob[i]->receive_damage("qi", damage );
			if( (int)ob[i]->query("neili") < skill * 2 )
				ob[i]->receive_wound("qi", damage);
			tell_object(ob[i], HIB"忽然眼前黑影狂舞，你覺得眼前一陣陰氣直襲面門，全身驟然感到要被撕裂開一樣！\n"NOR);
		}
		if( userp(ob[i]) ) ob[i]->fight_ob(me);
		else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
	}
*/
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
	int d_e1 = 20;
	int d_e2 = 5;
	int p_e1 = -20;
	int p_e2 = -60;
	int f_e1 = 300;
	int f_e2 = 600;
	int i, lvl, seq, ttl = sizeof(action);

	seq = random(ttl);       /* 選擇出手招數序號 */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage_type" : random(2) ? "抓傷" : "內傷",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me)
    { 
      if ((int)me->query("shen")<=-100000) return 1; 
      else if ((int)me->query("shen")<0)  return 0.8;
      else return 0.6;
     }

void skill_improved(object me)
{
	tell_object(me, HIR"你忽然從心底生出一股惡念：殺、殺、殺！我要殺絕天下人！\n" NOR );
//	me->add("shen", -200);
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/3) > victim->query_str() ) 
	{
    victim->receive_wound("qi", (damage_bonus - 80) / 3, me);
		return HIR "你聽到「喀啦」一聲輕響，竟似是骨碎的聲音！\n" NOR;	
	}
}

int help(object me)
{
	write(HIC"\n九陰白骨爪："NOR"\n");
	write(@HELP

    徽宗皇帝於政和年間，遍搜普天下道家之書，雕版印行，一共
有五千四百八十一卷，稱為‘萬壽道藏’。皇帝委派刻書之人，叫
做黃裳。他生怕這部大道藏刻錯了字，皇帝發覺之後不免要殺他的
頭，因此上一捲一捲的細心校讀。他居然便因此精通道學，更因此
而悟得了武功中的高深道理。他無師自通，修習內功外功，竟成為
一位武功大高手。他因此涉及江湖仇殺，退隱山林。不知不覺竟已
過了四十多年，終於對每一個敵人所使過的招數，他都想通了破解
的法子對付。於是出得山來，去報仇雪恨。不料那些敵人全都已不
在人世了。黃裳心想：‘原來我也老了，可也沒幾年好活啦。’他
花了這幾十年心血，想出了包含普天下各家各派功夫的武學，過得
幾年，這番心血豈不是就此湮沒？於是他將所想到的法門寫成了上
下兩卷書，那就是《九陰真經》。九陰白骨爪就是依此書練成的霸
道功夫。

	學習要求：
		內力200
HELP
	);
	return 1;
}

