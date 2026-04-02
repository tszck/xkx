// qiantang.c 事件：錢塘江潮信
// for XKX100 , by Sir 2003.11.3

#include <ansi.h>

// 獎勵
private void do_bonus(object room)
{
        object *obs;
        string msg;
        int lvl,p_bonus,s_bonus;
        int i;

        obs = all_inventory(room);
        if (sizeof(obs) < 1)
                return;
	
	msg = HIW "【自然奇觀】錢塘江潮信\n"NOR;
	msg += HIC "每年八月十八錢塘江漲潮，非常準時，故稱之爲潮信。 \n"
	          "每次潮水來臨時波濤洶湧，氣勢逼人，十分壯觀。\n";NOR;
        msg += HIC "只聽“隆隆”一陣雷鳴響過，潮水如湧一般的向岸邊捲來。\n"
                  "剎那間，漫江沸騰，波濤萬頃，潮高丈餘，萬馬奔騰，真有\n"
                  "“濤來勢轉雄，獵獵駕長風。雷震雲霓裏，山飛霜雪中”的\n"
                  "壯麗氣勢！正所謂“遠若素練橫江，聲如金鼓；近則亙如山\n"
                  "嶽，奮如雷霆”。一時間你不禁沉浸當中，天地萬物都已然\n"
                  "忘懷了。\n" NOR;
                                   
        msg += HIG "你望着洶湧的潮水，若有所悟，對武功又有了新的體會。\n" NOR;
        message("vision", msg, obs);

	message("channel:rumor", HIM"【謠言】"+"八月十八又到了，聽說不少人前往錢塘江觀潮。\n"NOR, users()); 
	        
        for ( i = 0 ; i < sizeof(obs); i++)  // 增加潛能基本內功及潛能
                {
                	if( !living(obs[i]) || !userp(obs[i]) ) continue;  
			p_bonus = 5000 + random( 5000 );
			s_bonus = 1000 + random( 500 );
			obs[i]->add("potential", p_bonus);
			obs[i]->add("score",s_bonus);
                        
			lvl = obs[i]->query_skill("force", 1);
                        if (lvl >= 50 && lvl< 300 )
                               	obs[i]->set_skill("force", lvl + 10);
                        else if ( lvl >= 300 )
                               	obs[i]->set_skill("force", lvl + 1);                                	                        
                          
                }
}

// 事件觸發
void trigger_event()
{
        object room;
                
        // 錢塘江潮信
        if (objectp(room = find_object("/d/hangzhou/qiantang")))
                do_bonus(room);
                
}

void create() 
{ 
	seteuid(getuid()); 
	message("channel:sys", HIR"【自然奇觀】錢塘江潮信。\n"NOR, users());
	trigger_event();
}