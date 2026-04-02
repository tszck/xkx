// lonely-sword.c 獨孤九劍
// Last Modified by sir 10.22.2001

#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h"

inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }
int action_po(object me, object victim, object weapon, int damage);//
int action_busy(object me, object victim, object weapon, int damage);
int action_damage(object me, object victim, object weapon, int damage);//
int action_parry(object me, object victim, object weapon, int damage);
int action_dodge(object me, object victim, object weapon, int damage);


string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *parry_msg = ({
	"卻見$n踏前一步，劍式斜指你的右臂，想要使$P閃身而退。\n",
	"$n以攻為守，以進為退，凝神運氣向$P猛攻快打地揮出方位大異的泰山"+(order[random(13)])+"「快活三」"NOR"三劍。\n",
	"$n劍法突變，劍勢伸縮不定，奔騰矯夭，逆使嵩山劍法的"+(order[random(13)])+"「天外玉龍」"NOR"企圖迫使$P變招。\n",
	"$n突然一劍點向$P的$l，雖一劍卻暗藏無數後着，$P手足無措，攻勢不由自主停了下來！\n",
	"$n不閃不避，舉劍閃電般使出"+(order[random(13)])+"「疊翠浮青」"NOR"反削$P的$l，想擋過你此招。\n",
	"$n突然使出青城派松風劍法的"+(order[random(13)])+"「鴻飛冥冥」"NOR"，可是方位卻有所偏差，長劍對着$P一絞，企\n圖突破$P的攻勢！\n",
	"$n挺劍一招象是"+(order[random(13)])+"「白雲出岫」"NOR"回刺$P的$l，企圖將$P的攻勢化解。\n",
	"只見$n不退反進，身如飄風，詭異地一式"+(order[random(13)])+"「天柱雲氣」"NOR"，動向無定不可捉摸地擋住了$P的\n進攻。\n",
	"$n不退反進，使出恆山劍招"+(order[random(13)])+"「綿裏藏針」"NOR"，森森劍氣充溢四周！架開了$P的這招\n",
});

mapping *action = ({
([	"action" : "但見$N挺身而上，$w一旋，一招彷彿泰山劍法的"+(order[random(13)])+"「來鶴清泉」"NOR"直刺$n
的$l！",
	"lvl" : 0,
	"skill_name" : "來鶴清泉"
]),
([	"action" : "$N奇詭地向$n揮出"+(order[random(13)])+"「泉鳴芙蓉」"NOR"、"+(order[random(13)])+"「鶴翔紫蓋」"NOR"、"+(order[random(13)])+"「石廩書聲」"NOR"、"+(order[random(13)])+"「
天柱雲氣」"NOR"及"+(order[random(13)])+"「雁回祝融」"NOR"衡山五神劍！",
	"lvl" : 10,
	"skill_name" : "衡山五神劍"
]),
([
	"action" : "$N劍隨身轉，續而刺出十九劍，竟然是華山"+(order[random(13)])+"「玉女十九劍」"NOR"，但奇的
是這十九劍便如一招，手法之快，直是匪夷所思！",
	"lvl" : 20,
	"skill_name" : "玉女十九劍"
]),
([	"action" : "$N劍勢忽緩而不疏，劍意有餘而不盡，化恆山劍法為一劍，向$n慢慢
推去！",
	"lvl" : 30,
	"skill_name" : "恆山劍法"
]),
([	"action" : "$N將$w隨手一擺，但見$n自己向$w撞將上來，神劍之威，實人所難測！",
	"lvl" : 40,
	"skill_name" : "神劍之威"
]),
([	"action" : "$N吐氣開聲，一招似是"+(order[random(13)])+"「獨劈華山」"NOR"，手中$w向下斬落，直劈向$n的
$l！",
	"lvl" : 50,
	"skill_name" : "獨劈華山"
]),
([	"action" : "$N含笑抱劍，氣勢莊嚴，$w輕揮，盡融"+(order[random(13)])+"「達摩劍」"NOR"為一式，閒舒地刺
向$n！",
	"lvl" : 60,
	"skill_name" : "達摩劍"
]),
([	"action" : "$N神聲凝重，$w上劈下切左右橫掃，挾雷霆萬鈞之勢逼往$n，"+(order[random(13)])+"「伏摩
劍」"NOR"的劍意表露無遺！",
	"lvl" : 70,
	"skill_name" : "伏摩劍"
]),
([	"action" : "卻見$N突然虛步提腰，使出酷似武當"+(order[random(13)])+"「蜻蜓點水」"NOR"的一招！",
	"lvl" : 80,
	"skill_name" : "蜻蜓點水"
]),
([	"action" : "$N運劍如風，劍光霍霍中反攻$n的$l，嘗試逼$n自守，劍招似是"+(order[random(13)])+"「伏
魔劍」"NOR"的"+(order[random(13)])+"「龍吞式」"NOR"。",
	"lvl" : 90,
	"skill_name" : "龍吞式"
]),
([	"action" : "$N抱劍旋身，轉到$n身後，雜亂無章地向$n刺出一劍，不知使的是什
麼劍法！",
	"lvl" : 100,
	"post_action" : (: action_busy :),
	"skill_name" : "雜亂無章"
]),
([	"action" : "$N劍挾刀勢，大開大闔地亂砍一通，但招招皆擊在$n攻勢的破綻，迫
得$n不得不守！",
	"lvl" : 110,
	"post_action" : (: action_parry :),
	"skill_name" : "大開大闔"
]),
([	"action" : "$N反手橫劍刺向$n的$l，這似有招似無招的一劍，威力竟然奇大，$n
難以看清劍招來勢！",
	"lvl" : 120,
	"post_action" : (: action_dodge :),
	"skill_name" : "有招似無招"
]),
([	"action" : "$N舉劍狂揮，迅速無比地點向$n的$l，卻令人看不出其所用是什麼招
式。",
	"lvl" : 130,
	"post_action" : (: action_busy :),
	"skill_name" : "舉劍狂揮"
]),
([	"action" : "$N突然運劍如狂，一手關外的"+(order[random(13)])+"「亂披風劍法」"NOR"，猛然向$n周身亂刺亂
削！",
	"post_action" : (: action_damage :),
	"lvl" : 140,
	"skill_name" : "亂披風劍法"
]),
([	"action" : "$N滿場遊走，東刺一劍，西刺一劍，令$n莫明其妙，分不出$N劍法的
虛實！",
	"lvl" : 150,
	"post_action" : (: action_dodge :),
	"skill_name" : "莫明其妙"
]),
([	"action" : "卻見$N身隨劍走，左邊一拐，右邊一彎，劍招也是越轉越加狠辣，竟
化"+(order[random(13)])+"「泰山十八盤」"NOR"為一劍攻向$n！",
	"lvl" : 160,
	"post_action" : (: action_damage :),
	"skill_name" : "泰山十八盤"
]),
([	"action" : "$N突然一劍點向$n的$l，雖一劍卻暗藏無數後着，$n手足無措，不知
如何是好！",
	"post_action" : (: action_busy :),
	"lvl" : 170,
	"skill_name" : "暗藏無數"
]),
([	"action" : "$N臉上突現笑容，似乎已看破$n的武功招式，胸有成竹地一劍刺向$n
的$l！",
	"post_action" : (: action_parry :),
	"lvl" : 180,
	"skill_name" : "突現笑容"
]),
([	"action" : "$N手中$w越轉越快，使的居然是衡山的"+(order[random(13)])+"「百變千幻雲霧十三式」"NOR"，劍
式有如雲卷霧湧，旁觀者不由得目為之眩！",
	"lvl" : 190,
	"post_action" : (: action_dodge :),
	"skill_name" : "百變千幻雲霧十三式"
]),
([	"action" : "$N劍意突煥氣象森嚴，便似千軍萬馬奔馳而來，長槍大戟，黃沙千里
，盡括嵩山劍勢擊向$n的$l！",
	"lvl" : 200,
	"post_action" : (: action_damage :),
	"skill_name" : "長槍大戟"
]),
([	"action" : "$N舉起$w運使"+(order[random(13)])+"「太極劍」"NOR"劍意，劃出大大小小無數個圓圈，無窮無盡
源源不絕地纏向$n！",
	"post_action" : (: action_busy :),
	"lvl" : 210,
	"skill_name" : "太極劍"
]),
([	"action" : "$N劍招突變，使出衡山的"+(order[random(13)])+"「一劍落九雁」"NOR"，削向$n的$l，怎知劍到中
途，突然轉向，大出$n意料之外！",
	"lvl" : 220,
	"post_action" : (: action_parry :),
	"skill_name" : "一劍落九雁"
]),
([	"action" : "$N隨手一劍指向$n，落點正是$n的破綻所在，端的是神妙無倫，不可
思議！",
	"post_action" : (: action_po :),
	"lvl" : 230,
	"skill_name" : "神妙無倫"
]),
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
string query_parry_msg(string limb)
{
	return parry_msg[random(sizeof(parry_msg))];
}
int valid_learn(object me)
{
	object ob;

	mapping myfam;
	myfam = (mapping)me->query("family");
	if(!myfam || myfam["family_name"] != "華山派"|| myfam["master_id"] != "feng qingyang")
		return notify_fail("獨孤九劍只有向風清揚老前輩學習。\n");
	if( (int)me->query("max_neili") < 600 )
		return notify_fail("你的內力不夠，沒有辦法練獨孤九劍。\n");
	if( (int)me->query_skill("zixia-shengong",1)<100)
		return notify_fail("獨孤九劍必須配合紫霞神功才能練習。\n");
	if( !(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必須先找一把劍才能練劍法。\n");
	if ((int)me->query_skill("lonely-sword",1) > 120)
		return notify_fail("這套劍法我就教到這兒，以後就要靠你自己練了。\n");

	return 1;
}
int practice_skill(object me)
{
	return notify_fail("獨孤九劍只能通過「總訣式」來演練。\n");
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
	int d_e1 = -25;
	int d_e2 = -5;
	int p_e1 = -55;
	int p_e2 = -35;
//	int f_e1 = 150;
//	int f_e2 = 230;
//	int m_e1 = 220;
//	int m_e2 = 320;
	int f_e1 = 230;
	int f_e2 = 150;
	int m_e1 = 320;
	int m_e2 = 220;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("lonely-sword", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* 獲得招數序號上限 */
			break;
		}
	seq = random(seq);       /* 選擇出手招數序號 */
	if (!userp(me) || me->query("family/master_id")== "feng qingyang" )
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"post_action" : action[seq]["post_action"],
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : random(2) ? "割傷" : "刺傷",
	]);
  else	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
//		"post_action" : action[seq]["post_action"],
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : random(2) ? "割傷" : "刺傷",
	]);
}


int action_damage(object me, object victim, object weapon, int damage)
{
       	string msg;
        string *limbs=victim->query("limbs");
        int dam;
        int skill= me->query_skill("lonely-sword", 1);
        if (!me->is_fighting(victim)) return 0;
	      if( damage == RESULT_DODGE && !victim->is_busy()
	            && skill > 100
	            && me->query("neili") > 100
	            && random(skill) > victim->query_skill("force",1)/2 ) //躲過
        {
        	me->add("neili",-50);
        	message_combatd("\n$N一聲長嘯:"HIW"「劍旋離身，劍嘯震山河」"NOR", 瞬間劍芒大作,朝$n激射而至！\n",me,victim);
          dam = skill*2 + me->query_temp("apply/damage");
          dam -= victim->query_temp("apply/armor");
          if (dam < 0 ) dam = 0;
          victim->receive_damage("qi",dam);
          msg = damage_msg(dam, "刺傷"); //此次傷害
          msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
          msg = replace_string(msg, "$w", weapon->query("name"));
          message_combatd(msg,me,victim);
          COMBAT_D->report_status(victim);
          return 1;
        }
        else if (  damage > 0 && !victim->is_busy()
	            && skill > 100
	            && me->query("neili") > 100
	            && random(skill) > victim->query_skill("force",1)/4)   //打中對方
        {
        	me->add("neili",-50);
          message_combatd("\n$N突然悟出"HIW"「練精化氣, 練氣化神, 練神還虛」"NOR"之真理, 手中長劍突然消失, 朝$n飛至！\n",me,victim);
          dam = skill + me->query_temp("apply/damage");
          dam -= victim->query_temp("apply/armor");
          if (dam < 0 ) dam = 0;
          victim->receive_damage("qi",dam);
          msg = damage_msg(skill*2, "刺傷"); //此次傷害
          msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
          msg = replace_string(msg, "$w", weapon->query("name"));
          message_combatd(msg,me,victim);
          COMBAT_D->report_status(victim);
        	return 1;
        }
        return 1;

}

int action_po(object me, object victim, object weapon, int damage)
{
	// 破對方武功、內功  為終極效果
	      int skill= me->query_skill("lonely-sword", 1);
        string v_force = victim->query_skill_mapped("force");
        int jiali;
        if (!me->is_fighting(victim)) return 0;
	      if (damage > 0)// 打中對方 破內功 或者破內力
	      {
	      	if (v_force && skill > 250 
	      	   && random(skill/2) > random(victim->query_skill("force"))  
	      	   && random(skill) > 200 
	      	   && victim->query_map_skill("force") 
	      	   && random(3)==1 )
	      	{
	      		me->add("neili",-100);
	      		victim->map_skill("force");
            message_combatd(HIC "$N一劍得手，劍招源源而出，劍尖直刺$n丹田！\n",me,victim);
            message_combatd(RED "$n只覺混身如遭電擊，真氣勁力紊亂難控，已然不能施展"+to_chinese(v_force)+"！\n" NOR,me,victim);
	        return 1;
	        }
	        else if (random(me->query_skill("lonely-sword",1)) > 100 &&
          random(me->query_skill("sword",1))>100 &&
         	me->query_skill("force",1) > 120
      	  && !victim->is_busy() )	
          {
          	me->add("neili",-50);
            if (victim->query("neili")>600)
               victim->add("neili", -500);
            else
               victim->set("neili",0);
          message_combatd(HIC "\n$N一劍得手，劍招源源而出，欲將$n團團困住！\n",me,victim);
          message_combatd(HIM "$n急運內力，使出渾身解數，方才脫出劍圈！\n"NOR , me, victim);
          return 1;
          }        
	      }
        else if( damage == RESULT_DODGE && !victim->is_busy()) //躲過  震懾對方
        {
        	me->add("neili",-50);
        	message_combatd(HIY "$n只覺$N劍中暗藏無數玄機，稍一膽怯，不敢攻上前去！\n"NOR,me,victim);
          victim->start_busy(1+random(skill/50));
        	return 1;
        }
        else if ( damage == RESULT_PARRY ) //對手招架住 可順勢再創對手
        {
        	jiali = me->query("jiali");
          if (!jiali) jiali=10;
	        if( random(skill)>140 )
	        {
	        	me->add("neili",-50);
            message_combatd(HIC "$N相交一招，已然看破$n武功套路，胸有成竹地刺出一劍!\n",me,victim);
	          victim->receive_wound("qi", (random(jiali)*2+100));
	          message_combatd(HIM"$N劍氣縱橫! 一道劍氣劃過了$n的胸口。結果鮮血狂噴!\n"NOR,me,victim);
            COMBAT_D->report_status(victim,1);
           }
        	return 1;
        }
        return 1;
	
}
int action_busy(object me, object victim, object weapon, int damage)
{
	      int skill=me->query_skill("lonely-sword",1);
        if (!me->is_fighting(victim)) return 0;
        if( damage <= 0 && !victim->is_busy() 
            && skill > 100
            && me->query("neili") > 100
            && random(me->query("combat_exp")) > victim->query("combat_exp")/3 ) //威力極小,如果沒有上兩個 則包括躲過和招架
        {
         me->add("neili",-50);
         message_combatd("$N頓然領悟了"HIW"「劍在神先, 綿綿不絕」"NOR"之真意, 劍尖瞬間爆出無數大大小小,\n正反斜直各種各樣的圓圈, 將$n團團困住。\n",me,victim);
         victim->start_busy(2+random(skill/50));
       	return 1;
        }
	      else if (damage > 0  && !victim->is_busy() 
          && skill > 100
	        && random(skill) > victim->query_skill("force",1)/3)
	      {
	      	  me->add("neili",-30);
	         	message_combatd(CYN"$N以意馭劍，畫出數個"RED"圓圈"CYN"，左右兼顧，將$n纏在正中！\n" NOR,me,victim);
		        victim->start_busy(1+random(skill/50));
	      }
	      return 1;
}

int action_dodge(object me, object victim, object weapon, int damage)
{
	      int skill=me->query_skill("lonely-sword",1);
	      string msg;
        string *limbs=victim->query("limbs");
        if (!me->is_fighting(victim)) return 0;
        if (random(me->query_skill("lonely-sword",1)) >= 200 &&
            random(me->query_skill("sword",1))>180 &&
          	me->query_skill("force",1) >= 200 &&
          	victim->query_map_skill("dodge")
           	)
       {
          me->add("neili", -50);
          victim->map_skill("dodge");
         if( !victim->is_busy() )
         {
           victim->start_busy(random(3)+1);
         }
         msg = HIC "\n$N突然舉劍一刺，劍招隨便無章，卻莫明奇妙地突破了$n的攻勢，大出$n意料！\n" ;
         msg += HIR"$n大喫一驚，竟然忘了閃避！\n"NOR;
         message_combatd(msg,me,victim);
         return 1;
       }
	     else if (damage <= 0 && random(skill) > random(victim->query_skill("dodge",1)/3))
       {          
          me->add("neili", -50);
  	      message_combatd("\n卻見$N飄身而上，半空中舉劍上挑，劍光已封住了$n身週數尺之地，攻得精巧無比！\n",me,victim);
  	      victim->receive_damage("qi",skill/2);
          msg = damage_msg(skill/2, "刺傷");
          msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
          msg = replace_string(msg, "$w", weapon->query("name"));
          message_combatd(msg,me,victim);
          COMBAT_D->report_status(victim);
          return 1;
       }
       return 1;
}

int action_parry(object me, object victim, object weapon, int damage)
{
	     int skill=me->query_skill("lonely-sword",1);
       string msg;
       string *limbs=victim->query("limbs");
        if (!me->is_fighting(victim)) return 0;
       if (damage == RESULT_DODGE &&
           random(me->query_skill("lonely-sword",1)) > 140 &&	
	         random(me->query_skill("sword",1))>140 &&
           me->query_skill("force",1) >= 200 &&
          	victim->query_map_skill("parry")
           )	
         {
           me->add("neili", -50);
           victim->map_skill("parry");
           if( !victim->is_busy() )
           {
             victim->start_busy(random(2)+1);
           }
           msg = HIC "\n$N舉劍反攻，後發先至地刺向$n，不僅把$n招術封死，更進一步發出攻擊！\n" NOR;
           msg += HIY"$n難以看清劍招來勢,竟然忘了招架！\n"NOR;
           message_combatd(msg,me,victim);
        }
	      else if (damage <= 0 && random(skill) > random(victim->query_skill("parry",1)/3))
       {
          me->add("neili", -50);
        	msg = "\n$N一個箭步縱到$n身前，手腕微顫，揮劍斜撩，橫削$n$l，劍法極盡靈動輕捷\n";
  	      victim->receive_damage("qi",skill/2);
          msg += damage_msg(skill/2, "刺傷"); //此次傷害
          msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
          msg = replace_string(msg, "$w", weapon->query("name"));
          message_combatd(msg,me,victim);
          COMBAT_D->report_status(victim);
       }
}
//被擊中效果
mixed be_hit_ob(object me, object ob, int damage, int factor)
{
		   object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        if ((int)me->query("qi")>1 && (int)me->query("eff_qi")>1)
            i = (int)me->query("eff_qi") / (int)me->query("qi") + 1;
        else i=1;
        if ( i > 5 ) i = 5;
        limbs = ob->query("limbs");
        level = me->query_skill("lonely-sword", 1);

//        if( me->is_busy()) return 0;
        if( damage < 100 ) return 0;
        if ( living(me) 
         && !me->query_temp("noliving")
         && random(level) > 100 /i 
         && me->query_skill_mapped("sword") =="lonely-sword"
         && me->query_skill_mapped("parry") =="lonely-sword"
         && weapon
         && weapon->query("skill_type") == "sword"
         && me->query_skill("sword") > 300
         && random(me->query_skill("sword",1)) > 150
         && me->query("neili") > 200 
         && me->query("max_neili") >= 3000
         && random(me->query_int()) >= 20 ){
            me->add("neili", -100);
            msg = HIW"$N行動不便，知道這一招無可躲避，當即挺劍刺出，後發先至，噗的一聲刺向$n的咽喉。\n"NOR;
            if ( random(level) > ob->query_skill("dodge", 1) / i){
             q = damage * i ;
             if ( q > 3500 ) q = 3500 + ( q - 3500 )/ 100;
             ob->receive_damage("qi", q);
             ob->receive_wound("qi", q/3);
             if (!ob->is_busy())
             ob->start_busy(2+random(2));
     //        if ( random(me->query("combat_exp")) > ob->query("combat_exp") / i)
             p = ob->query("qi")*100/ob->query("max_qi");
             msg += damage_msg(q, "刺傷") + "( $n"+status_msg(p)+" )\n";
             msg = replace_string(msg, "$l", "喉嚨");
             msg = replace_string(msg, "$w", weapon->query("name"));
           //  j = -(damage/2+random(damage/2));
             j = 0;
            }
            else {
              dodge_skill = ob->query_skill_mapped("dodge");
              if( !dodge_skill ) dodge_skill = "dodge";
              msg += SKILL_D(dodge_skill)->query_dodge_msg(ob);
              j = -damage/4; 
            }
            message_combatd(msg, me, ob);
            return j;
        }
}

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
	return __DIR__"lonely-sword/" + action;
}

int help(object me)
{
	write(HIC"\n獨孤九劍："NOR"\n");
	write(@HELP

    “獨孤九劍，有進無退！”
    創制這套劍法的獨孤求敗前輩，名字叫做‘求敗’，他畢生想
求一敗而不可得，這劍法施展出來，天下無敵，當年他仗劍江湖，
無敵於天下，連找一個對手來逼得他回守一招都不可得，委實令人
可驚可佩。
    無招勝有招，敵強我更強。獨孤九劍不含招式，有招既無招，
無招亦有招。獨孤九劍要旨在於「悟」，不可拘泥不化，講究料敵
機先，出奇制勝。通曉了九劍劍意，則無所施而不可。
    獨孤九劍，自“總訣式”、“破劍式”、“破刀式”以至“破
槍式”、“破鞭式”、“破索式”、“破掌式”、“破箭式”而到
第九劍“破氣式”。九劍的第一招“總訣式”，有種種變化，用以
體演總訣，便於修習。第二招“破劍式”，用以破解普天下各門各
派的劍法。第三招“破刀式”，用以破解單刀、雙刀、柳葉刀、鬼
頭刀、大砍刀、斬馬刀種種刀法。第四招“破槍式”，包括破解長
槍、大戟、蛇矛、齊眉棍、狼牙棒、白蠟杆、禪杖、方便鏟種種長
兵刃之法。第五招“破鞭式”，用以破解鋼鞭、鐵鐧、點穴橛、拐
子、蛾眉刺、匕首、板斧、鐵牌、八角槌、鐵椎等等短兵刃，第六
招“破索式”，破解的是長索、軟鞭、三節棍、鏈子槍、鐵鏈、漁
網、飛錘流星等等軟兵刃。第七招“破掌式”，破的是拳腳指掌上
的功夫，將長拳短打、擒拿點穴、魔爪虎爪、鐵沙神掌，諸般拳腳
功夫盡數包括內在。第八招“破箭式”這個“箭”字，則總羅諸般
暗器，練這一劍時，須得先學聽風辨器之術，不但要能以一柄長劍
擊開敵人發射來的種種暗器，還須借力反打，以敵人射來的暗器反
射傷敵。第九劍“破氣式”，是為對付身具上乘內功的敵人而用，
神而明之，存乎一心。

	學習要求：
		只能向風清揚學習
		紫霞神功100級
		內力600
HELP
	);
	return 1;
}

