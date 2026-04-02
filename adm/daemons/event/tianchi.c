// emei.c 事件：長白山天池流星
// for XKX100 , by Sir 2003.11.3

#include <ansi.h>

// 獎勵
private void do_bonus(object room)
{
        object *obs;
        string msg;
        int lvl,p_bonus,s_bonus;
        int r,i;

        obs = all_inventory(room);
        if (sizeof(obs) < 1)
                return;

        r = random(365);
        if (r == 0)
        {
        	msg = HIW "【自然奇觀】天池流星雨\n"NOR;
                msg += HIC "只聽天空驟然傳來一陣刺耳的摩擦聲，你仰望上蒼，發現穹蒼裏已豁然出現\n"
                           "無數顆流星。夜隕如雨飛墜，鋒芒劃空，爾落入天池之中，又再激起萬股七\n"
                           "色浪濤，漆黑夜穹竟猶如白晝一般。你不禁感嘆，大自然之威，當真神鬼莫\n"
                           "測。\n" NOR;

                msg += HIG "你仔細的觀察了流星雨的全過程，發現其中竟有很多奧祕可以融於武學。\n" NOR;
                
                for ( i = 0 ; i < sizeof(obs); i++)  // 增加潛能基本輕功基本暗器
                {
                	if( !living(obs[i]) || !userp(obs[i]) ) continue;                
			p_bonus = 5000 + random( 5000 );
			s_bonus = 1000 + random( 500 );
			obs[i]->add("potential", p_bonus);
			obs[i]->add("score",s_bonus);
                        
			lvl = obs[i]->query_skill("throwing", 1);
                        if (lvl >= 50 && lvl< 300 )
                               	obs[i]->set_skill("throwing", lvl + 10);
                        else if ( lvl >= 300 )
                               	obs[i]->set_skill("throwing", lvl + 1);
                                	
                        lvl = obs[i]->query_skill("dodge", 1);
                        if (lvl >= 50 && lvl< 300 )
                               	obs[i]->set_skill("sword", lvl + 10);
                        else if ( lvl >= 300 )
                               	obs[i]->set_skill("sword", lvl + 1);
                }
                
                
                message("vision", msg, obs);
                message("channel:rumor", HIM"【謠言】"+"聽說長白山天池上夜空竟現流星雨，五彩繽紛，煞爲壯觀。\n"NOR, users());
        } else
        if (r < 40)
        {
        	msg = HIW "【自然奇觀】夜空流星\n"NOR;
                msg += HIC "只聽遠處一陣刺耳的摩擦聲，舉目望去，發現竟有流星從天邊劃過，怎奈距\n"
                          "隔委實太遠，根本無法看清。\n" NOR;

                msg += HIG "你觀罷流星，隱隱的對武學有了一絲體會。\n" NOR;

                for ( i = 0 ; i < sizeof(obs); i++)
                {
                	if( !living(obs[i]) || !userp(obs[i]) ) continue;
			p_bonus = 500 + random( 500 );
			s_bonus = 200 + random( 200 );			
			obs[i]->add("potential", p_bonus);
			obs[i]->add("score", s_bonus);
		}      
                message("vision", msg, obs);

        } else
        {
                switch (random(2))
                {
                case 0:
                        msg = WHT "眼見天邊一片明亮，知是流星雨將至，可怎奈間隔遙且雲層厚，卻無緣得見。\n" NOR;
                        break;
                default:
                        msg = WHT "眼見天邊一片明亮，但是水氣，霧氣和雲層交雜，讓你什麼都看不清楚。\n" NOR;
                        break;
                }
                msg += HIG "你心中連嘆：“太可惜了！”\n" NOR;

                message("vision", msg, obs);
        }
}

// 事件觸發
void trigger_event()
{
        object room;

        // 長白山天池夜隕
        if (objectp(room = find_object("/d/guanwai/tianchi1")))
                do_bonus(room);
}

void create() 
{ 
	seteuid(getuid()); 
	message("channel:sys", HIR"【自然奇觀】長白山天池流星。\n"NOR, users());
	trigger_event();
}
