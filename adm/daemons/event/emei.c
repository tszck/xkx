// emei.c 事件：峨嵋金頂日出
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
                msg = HIY "【自然奇觀】峨嵋佛光\n"NOR;
                msg += HIR "只見太陽一點一點的升了起來，倏的眼前一亮，一道光暈出現在雲際，\n"
                          "朦朦朧朧似乎有一個佛影立在當中，令人歎羨不已。\n" NOR;
                msg += HIG "你冥冥中彷彿得到了佛主的指示，登時有茅塞頓開的感覺。\n" NOR;
                
               
               

                // 佛門弟子增加佛學技能
                for ( i = 0 ; i < sizeof(obs); i++)
                {
                	if( !living(obs[i]) || !userp(obs[i]) ) continue;
			p_bonus = 5000 + random( 5000 );
			s_bonus = 1000 + random( 500 );
			obs[i]->add("potential", p_bonus);
			obs[i]->add("score",s_bonus);
                        if (obs[i]->query("class") == "bonze")
                           {
				lvl = obs[i]->query_skill("buddhism", 1);
                        	if (lvl >= 50 && lvl< 200 )
                                	obs[i]->set_skill("buddhism", lvl + 1);
                                
				lvl = obs[i]->query_skill("mahayana", 1);
                        	if ( lvl >= 50 && lvl < 200)
                                	obs[i]->set_skill("mahayana", lvl + 1);
				lvl = obs[i]->query_skill("lamaism", 1);
                        	if (lvl >= 50 && lvl <200 )
                                	obs[i]->set_skill("lamaism", lvl + 1);
                            }
                }

                message("vision", msg, obs);
		message("channel:rumor", HIM"【謠言】"+"聽說峨嵋金頂佛光出現，令人歎爲觀止，讚歎不已。\n"NOR, users());
               
        } else
        if (r < 250)
        {
        	msg = HIY "【自然奇觀】峨嵋日出\n"NOR;
        	msg +=HIG "在峨嵋山上欣賞日出令人心曠神怡，格外領略峨嵋山的雋秀險奇。\n"NOR;
        	
                switch (random(3))
                {
                case 0:
                        msg += HIY "一輪紅日躍出天際，映射得層巒疊翠分外妖嬈，茫茫雲海，盡披紅妝。\n" NOR;
                        break;
                case 1:
                        msg += HIY "忽然間一輪紅日躍了上來，天地之間登時輝煌無比，只射得你眼睛都無法睜開。\n" NOR;
                        break;
                default:
                        msg += HIY "驀然眼前金光四射，一輪紅日冉冉升起。\n" NOR;
                        break;
                }
                msg += HIG "你心頭閃過一道靈光，似乎受到了某種啓迪。\n" NOR;
                
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
                        msg = WHT "眼見太陽朦朦朧朧的就要升上來，卻見一片烏雲飄過，遮了個嚴嚴實實。\n" NOR;
                        break;
                case 1:
                        msg = WHT "你眼前越來越亮，但是霧氣好重，讓你什麼都看不清楚。\n" NOR;
                        break;
                default:
                        msg = WHT "天邊漸漸的發白，但是一層一層的雲氣將日頭壓得光芒一絲都看不見。\n" NOR;
                        break;
                }
                msg += HIG "你心中連嘆：“太可惜了！”\n" NOR;

                message("vision", msg, obs);
        }
}

//事件觸發
void trigger_event()
{
        object room;

        // 峨嵋金頂日出
        if (objectp(room = find_object("/d/emei/jinding")))
                do_bonus(room);
}

void create() 
{ 
	seteuid(getuid()); 
	message("channel:sys", HIR"【自然奇觀】峨嵋金頂日出。\n"NOR, users());
	trigger_event();
}