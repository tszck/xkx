// wuliang.c 事件：無量山玉壁劍舞
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

        r = random(100);
        if (r == 0)
        {
        	msg = HIG "【自然奇觀】無量山玉壁劍舞\n"NOR;
                msg += HIW "只見皎潔的月光下，兩個飄逸絕倫的身影倒映在對面山壁之上，持劍翩翩起\n"
                           "舞，劍光頓挫，仙影迴翔。你不由驚歎：寰宇之中，竟有如此絕奧之技，今\n"
                           "日有緣得見仙人之姿，實在是福分非淺。\n" NOR;
                msg += HIG "你對仙人的劍舞頗有所感，武學上頓時有了新的領悟。\n" NOR;

                message("vision", msg, obs);
		for ( i = 0 ; i < sizeof(obs); i++)  // 增加潛能基本劍法及基本身法
                {
                	if( !living(obs[i]) || !userp(obs[i]) ) continue;
			p_bonus = 5000 + random( 5000 );
			s_bonus = 1000 + random( 500 );
			obs[i]->add("potential", p_bonus);
			obs[i]->add("score",s_bonus);
                        
			lvl = obs[i]->query_skill("sword", 1);
                        if (lvl >= 50 && lvl< 300 )
                               	obs[i]->set_skill("sword", lvl + 10);
                        else if ( lvl >= 300 )
                               	obs[i]->set_skill("sword", lvl + 1);
                                	
                        lvl = obs[i]->query_skill("dodge", 1);
                        if (lvl >= 50 && lvl< 300 )
                               	obs[i]->set_skill("dodge", lvl + 10);
                        else if ( lvl >= 300 )
                               	obs[i]->set_skill("dodge", lvl + 1);
                          
                }
                message("channel:rumor", HIM"【謠言】"+"聽說大理無量山又出仙人劍舞，仙影玄奇，令人匪夷所思。\n"NOR, users());        
        } else
        if (r < 60)        
        {	
        	msg = HIG "【自然奇觀】無量山玉壁仙影\n"NOR;
        	msg += HIW"皎潔的月光下，壁上能隱隱約約倒影出仙人之姿。實乃世間僅有。\n"NOR;
        	
                switch (random(3))
                {
                case 0:
                        msg += HIW "只見對面無量山玉壁上仙影一閃即過，身形之敏捷，令你根本無法捕捉。\n" NOR;
                        break;
                case 1:
                        msg += HIW "只見無量山玉壁上閃過幾道仙影，似乎是施展一種奇妙無比的武功絕學。\n" NOR;
                        break;
                default:
                        msg += HIW "忽然間兩個飄逸絕倫的身影顯映在對面山上，但仙影轉瞬即逝，你根本無法看清。\n" NOR;
                        break;
                }
                msg += HIG "你受到了仙影的感悟，武學方面又有了一些體會。\n" NOR;
                
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
                switch (random(3))
                {
                case 0:
                        msg = WHT "眼見皎潔的月光升起，可是一團雲飄過，遮蓋了月光，你眼前頓時一片漆黑。\n" NOR;
                        break;
                case 1:
                        msg = WHT "你目不轉睛的注視着對面的玉壁，可剎那間雷聲轟鳴，山風捲雲，將月光遮了個嚴實。\n" NOR;
                        break;
                default:
                        msg = WHT "夜晚已至，可一團團濃厚的雲層卻籠罩着天空，你連對面的山頭都無法看清。\n" NOR;
                        break;
                }
                msg += HIG "你不禁嘆息道：“怎奈緣分未至，無緣窺視仙影！”\n" NOR;

                message("vision", msg, obs);
        }
}

// 事件觸發
void trigger_event()
{
        object room;

        // 無量山玉壁劍舞
        if (objectp(room = find_object("/d/xiaoyao/pubu")))
                do_bonus(room);
}

void create() 
{ 
	seteuid(getuid()); 
	message("channel:sys", HIR"【自然奇觀】無量山玉壁劍舞。\n"NOR, users());
	trigger_event();
}