// pkd.c 
// 華山論劍系統主程序
// for XKX100 , by Sir 2004.1.13

inherit F_DBASE;
inherit F_CLEAN_UP;

#include <ansi.h>
#include <localtime.h>



#define ENTRY_ROOM      "/d/huashan/sheshen"
#define READY_ROOM      "/d/huashan/pk/entry"
#define PK_ROOM         "/d/huashan/pk/turen"
#define PK_DIR		"/d/huashan/pk/"

// 系統主控狀態
nosave int state;

#define SLEEPING        0
#define GET_READY       1
#define STARTING        2

#define GET_READY_TIME  180

nosave int start = -2 ;
nosave int ready_time = 0;

nosave mapping *tlist = ({
([      "name" : ({"華山論劍之少俠試劍","華山論劍之名俠比劍","華山論劍之大俠評劍","華山論劍之宗師論劍"}),
        "time" : ({ 2,4,6,8,10,12,14,16,18,20,22,24 }),
        "minexp" : ({ 100000, 1000000,3000000, 5000000}),
        "maxexp" : ({ 1500000,4000000,8000000,2000000000}),
        "last_lvl" : -1,
        "lvl_num" : 4,
        "time_num" : 12,
]),
});
nosave int selected=-2;

void change_state(int new_state);
int  start_competition();
void auto_check();
void give_bouns(object me);
void kickout_players();
void send_invite_message();

// 查詢主控狀態
int is_pking()              { return state == STARTING; }
int is_ready()              { return state == GET_READY; }

void create()
{
        seteuid(ROOT_UID);       
        message("channel:sys", HIR"\n【華山論劍】華山論劍已經啓動。\n"NOR, users());
        state = SLEEPING;
        set_heart_beat(10);
}

// 從ENTER_ROOM進入READY_ROOM 等待比賽開始
int join_competition(object ob)
{
        int exp;
        if (state == STARTING )
        {
        	tell_object(ob,"公平子對你說道：“現在華山之顛正在舉行活動，你還是等等再說吧。”\n");
                return 1;
        }
        if (state == SLEEPING )
        {
        	tell_object(ob,"公平子對你說道：“舉行華山論劍的日子還沒到呢，你還是等等再說吧。”\n");
                return 1;
        }
       
        if (ob->query_condition())
        {
        	tell_object(ob,"公平子對你說道：“你現在狀態不佳，還是別進去了。”\n");
                return 1;
        }               
        if (present("mian ju", ob) )
        {
        	tell_object(ob,"公平子對你說道：“不能帶面具入內！”\n");
                return 1;
        } 
    	if (present("helan huoqiang", ob) )
    	{
        	tell_object(ob,"公平子對你說道：“不能帶火槍入內！”\n");
                return 1;
        }
        exp = ob->query("combat_exp");
        if (exp < tlist[0]["minexp"][selected])
        {
        	tell_object(ob,"公平子對你說道：“閣下還是先提高點經驗再來參加論劍吧。”\n");
                return 1;
        }                

        if (exp > tlist[0]["maxexp"][selected])
        {
        	tell_object(ob,"公平子對你說道：“哦…您武功如此高強，這次還是別和小輩們爭了。”\n");
                return 1;
        }                   
       
        message("channel:snow", HIC"【華山論劍】"+"公平子：" + ob->query("name") + "進入紫竹林參加華山論劍。\n"NOR, users());

        tell_object(ob, HIY "你眼前忽然一花……\n" NOR);
        ob->move(READY_ROOM);
        tell_object(ob, HIY "你定神一看，這才發現自己已經到了紫竹林，你將在這裏等待比賽開始。\n"NOR);
        
//        set_heart_beat(5);
        return 0;
}

// 主控心跳
void heart_beat()
{
        mixed *lt;
        int j;
        int last_lvl;
        int flag;
        
//        message("channel:sys", HIR"\n【華山論劍】華山論劍心跳檢查。\n"NOR, users());
//        seteuid(ROOT_UID);
        lt = localtime(time());
	
        switch (state)
        {
        case SLEEPING: 
        	flag = 0;       	
        	last_lvl = tlist[0]["last_lvl"];
        	for ( j = 0; j<tlist[0]["time_num"];j++)
        	{	        		        		        		              		
        		if ( (int)tlist[0]["time"][j] == (int)lt[LT_HOUR] && selected != last_lvl && start != (int)lt[LT_HOUR] )
        		{
        			tlist[0]["last_lvl"] = last_lvl + 1;
        			selected = last_lvl + 1;
        			start = (int)lt[LT_HOUR];
        			change_state(GET_READY);
        			ready_time = time();
        			flag = 1;
//        			if ( tlist[0]["last_lvl"] == 4 )
        			if ( tlist[0]["last_lvl"] == 3 )
        				tlist[0]["last_lvl"] = -1;
        			break;
        		}        		        				
        	}
        	if ( flag != 1 ) selected = -2;
        	flag = 0;
        	break;	        					        				        		        		        		        		               

        case GET_READY:        
            	if (time() < ready_time + GET_READY_TIME)
                        break;
                change_state(STARTING);
                break;

        case STARTING:
                break;
        }
        remove_call_out("auto_check");
        call_out("auto_check", 1);
//        auto_check();
}

// 改變控制狀態
void change_state(int new_state)
{
//        mixed lt;
        int n;

//        lt = localtime(time());
        switch (new_state)
        {
        case GET_READY:              
                kickout_players();
                ready_time = time();
                message("channel:snow", HIM"【謠言】"+"聽說一年一度的" + tlist[0]["name"][selected] + "馬上就要舉行了，不知道今年的第一是誰？\n"NOR, users());
//                set_heart_beat(5);
                send_invite_message();
                break;

        case STARTING:
                if (! (n = start_competition()))
                {
                       message("channel:snow", HIM"【謠言】"+"聽說今年的" + tlist[0]["name"][selected] + "因故取消了，真是沒勁。\n"NOR, users());
                       kickout_players();
                       new_state = SLEEPING;
                } else
                {
                       message("channel:snow", HIM"【謠言】"+"聽說今年的" + tlist[0]["name"][selected] + "吸引了" + chinese_number(n) +"名高手！走...看看熱鬧去。\n"NOR, users());      
//                        set_heart_beat(5);
                }
                break;

        default:
                break;
        }
        state = new_state;
//        if (state == SLEEPING)               	
//                set_heart_beat(30);        
        return;
}

// 比賽開始前 清理場地
void kickout_players()
{
        object *obs;
        object room;
        string *file;
        object *ob_list;
        int i,j;
	
	ob_list = children("/clone/quest/bwdhnpc");
        for(i=0; i<sizeof(ob_list); i++) 
	if(environment(ob_list[i]))
	{
		message_vision("$N笑道：華山論劍結束了，我也該走啦！\n",ob_list[i]);
		destruct(ob_list[i]);
        }
	file = get_dir(PK_DIR);        
        for ( i = 0 ; i <sizeof(file); i++)
        {
        	if(!( room = find_object(PK_DIR+file[i]) ))
			room = load_object(PK_DIR+file[i]);
		obs = all_inventory(room);		
		for ( j = 0 ; j <sizeof(obs); j++)
		{        
                	if (!living(obs[j]) || ! userp(obs[j]))
                	{                		
                        	destruct(obs[j]);
                        }
                	else 
              		{
                		tell_object(obs[j], HIC "\n公平子走了過來，嚷嚷道：“清場了！清場了，都快走吧！”\n" NOR);
                		obs[j]->delete_temp("bwdh_join");
                		obs[j]->delete_temp("bwdh_pknum");
                		obs[j]->delete_temp("bwdh_nknum");
                		obs[j]->remove_all_enemy(1);
				            obs[j]->remove_all_killer();
                		obs[j]->move(ENTRY_ROOM);
                		message("vision", "只見" + obs[j]->query("name") + "悻悻的被人抬了出來。\n",obs[j]); 
                	}
                } 
         }                    
}

object create_thief( object me )
{
	mapping name, hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;	
	object obj, thief_master, weapon;
	mapping skl;
	string *skillname;
	int skilllvl,topexp;
 int i,j;
	object *inv;
 string  weapon_type;
  string *masters = ({
	"baituo/ouyangfeng",	//lingshe-zhangfa	shexing-diaoshou hamagong
	"dali/duanzc",	//duanyun-fu		sun-finger
	"dali/daobaifeng",	//feifeng-whip		jinyu-quan 	wuluo-zhang
	"dali/yideng",	//duanjia-sword		six-finger
	"emei/miejue",	//huifeng-jian		jinding-zhang 	tiangang-zhi
	"emei/feng",         //yanxing-dao		jinding-zhang 	tiangang-zhi
	"gaibang/hong",		//dagou-bang		xianglong-zhang	suohou-hand
	"gaibang/jian",		//fengmo-staff		jianlong-zaitian
	"gumu/longnv",	//yunv-jian		meinv-quan
	"gumu/limochou",	//qiufeng-chenfa	meinv-quan
	"gumu/yangguo",	//xuantie-sword		anran-zhang
	"heimuya/dongfang",	//bixie-jian		xuantian-zhi
	"heimuya/ren",		//wuyun-jian		xuantian-zhi
	"heimuya/weng",		//shigu-bifa		xuantian-zhi
	"hengshan/xian",		//hengshan-jian		tianchang-zhang	chuanyun-shou
	"henshan/moda",		//hengshan-sword	biluo-zhang	luoyan-hand
	"honghua/chen-jialuo",	//luohua-jian		benlei-shou	baihua-cuoquan
	"honghua/wu-chen",	//zhuihun-jian		benlei-shou
	"huashan/yue-buqun",	//huashan-sword		huashan-ken
	"huashan/feng-buping",	//kuangfeng-jian	poyu-quan	hunyuan-zhang
	"huashan/feng",		//lonely-sword		poyu-quan	hunyuan-zhang
	"kunlun/hezudao",	//liangyi-sword		kunlun-strike
	"kunlun/hetaichong",	//xunlei-sword		zhentian-cuff	chuanyun-leg
	"lingjiu/tonglao",	//tianyu-qijian		liuyang-zhang	zhemei-shou
	"lingxiao/bai",		//xueshan-sword		snow-strike
	"lingxiao/shipopo",	//jinwu-blade		snow-strike
	"mingjiao/zhangwuji",	//shenghuo-ling		qishang-quan
	"mingjiao/yintianzheng",	//lieyan-dao		sougu
	"mingjiao/weiyixiao",	//liehuo-jian		hanbing-mianzhang
	"murong/murong-fu",	//murong-sword		canhe-finger	xingyi-strike
	"nanshaolin/tianhong",	//weituo-chu		jingang-cuff
	"nanshaolin/tianjing",	//riyue-whip		wuxiang-finger
	"qingcheng/yu",		//songfeng-jian		wuying-leg	cuixin-strike
	"quanzhen/wang",		//quanzhen-jian		chunyang-quan	haotian-zhang
	"quanzhen/ma",		//duanyun-bian		chunyang-quan	haotian-zhang
	"shaolin/da-mo",	//			nianhua-zhi	sanhua-zhang
	"shaolin/xuan-nan",	//wuchang-zhang		yizhi-chan  banruo-zhang
	"shaolin/du-nan",	//riyue-bian		jingang-quan
	"shenlong/hong",		//ruyi-hook		yingxiong-sanzhao	shenlong-bashi
	"shenlong/su",		//meiren-sanzhao	jueming-leg	huagu-mianzhang
	"shenlong/pang",		//shenlong-staff	huagu-mianzhang	jueming-leg
	"songshan/zuo",		//songshan-sword	songyang-strike	poyun-hand
	"taishan/tianmen",	//taishan-sword		kuaihuo-strike
	"taohua/huang",	//yuxiao-jian		tanzhi-shentong	lanhua-shou
	"taohua/lu",		//luoying-shenjian	xuanfeng-leg	luoying-zhang
	"tiezhang/qqren",	//			tiezhang-zhangfa
	"tiezhang/qqzhang",	//tiexue-qiang		zhusha-zhang
	"wudang/zhang",	//taiji-jian		taiji-quan
	"wudang/yu",		//liangyi-jian		taiji-quan
	"wudujiao/hetieshou",	//wudu-goufa		wudu-zhang	qianzhu-wandushou
	"xiaoyao/xiaoyaozi",	//ruyi-dao		zhemei-shou	liuyang-zhang
	"xingxiu/ding",		//			chousui-zhang	sanyin-wugongzhao
	"xingxiu/chuchen",	//tianshan-zhang	chousui-zhang	sanyin-wugongzhao
	"xueshan/jiumozhi",	//			huoyan-dao
	"xueshan/fawang",	//riyue-lun		dashou-yin	yujiamu-quan
	"xueshan/xuedao",	//xue-dao		dashou-yin
	"yunlong/chen",		//yunlong-jian		yunlong-zhua	yunlong-shou
});
	seteuid(getuid());
	obj = new("/clone/quest/bwdhnpc");
	if (random(2) == 0)
	{
		name = NAME_D->woman_name();
		obj->set("gender", "女性");
	}
	else
	{
		name = NAME_D->man_name();
		obj->set("gender", "男性");
	}

	hp_status = me->query_entire_dbase();
	obj->set("fname", name["name"]);
	obj->set("str", hp_status["str"]);
	obj->set("int", hp_status["int"]);
	obj->set("con", hp_status["con"]);
	obj->set("dex", hp_status["dex"]);
	obj->set("age", hp_status["age"]+2);

	obj->set("max_jing",  hp_status["max_jing"]*3/2);
	obj->set("eff_jing",  hp_status["max_jing"]*3/2);
	obj->set("jing",      hp_status["jing"]*3/2);
	
	if ((hp_status["max_qi"]*2)<1500)
	{ 
		obj->set("max_qi", 1500);
		obj->set("eff_qi", 1500);
		obj->set("qi",     1500);
	}  
	else		
	{
		obj->set("max_qi", hp_status["max_qi"]*2);
		obj->set("eff_qi", hp_status["max_qi"]*2);
		obj->set("qi",     hp_status["max_qi"]*2);
	}
	if ((hp_status["max_neili"])<1500)
	{
		obj->set("max_neili",1500);
		obj->set("jiali", 100);
	}
        else 
	{ 
		obj->set("max_neili", hp_status["max_neili"]);
		obj->set("jiali",     hp_status["max_neili"]/30);
	}
	if((hp_status["neili"])<1500)
	{
		obj->set("neili",1500);
	}
	else
	{
		obj->set("neili", hp_status["neili"]);	
	}
		
	topexp = (int) me->query("combat_exp") -  tlist[0]["minexp"][selected];
	topexp = tlist[0]["minexp"][selected] + random( topexp );
	obj->set("combat_exp", topexp );	
/* skill */
	skl = me->query_skills();
	skilllvl=30;	
	if (sizeof(skl))
	{
		skillname = sort_array( keys(skl), (: strcmp :) );
		for (j=0; j<sizeof(skl); j++)
		{
			if (skilllvl < skl[skillname[j]])
				skilllvl = skl[skillname[j]];
		}		
		skilllvl = skilllvl - skilllvl * 1/5 ;		
	}

//	family = keys( masters );
//	i = random( sizeof(family) );
//	thief_master = new ( CLASS_D(family[i])+"/"+masters[family[i]] );
	i = random( sizeof(masters) );
	thief_master = new ( CLASS_D(masters[i]) );
	if ( mapp(skill_status = thief_master->query_skills()) )
	{
		skill_status = thief_master->query_skills();
		sname = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++)
		{
			obj->set_skill(sname[i], skilllvl);
		}
	}
/* skill map*/
	if ( mapp(map_status = thief_master->query_skill_map()) )
	{
		mname = keys(map_status);

		for(i=0; i<sizeof(map_status); i++)
		{
			obj->map_skill(mname[i], map_status[mname[i]]);
		}
	}
/* skill prepare*/
	if ( mapp(prepare_status = thief_master->query_skill_prepare()) )
	{
		pname = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++)
		{
			obj->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}
	
	inv = all_inventory(thief_master);
	for ( i = 0; i < sizeof(inv); i++ )
		if( inv[i]->query("equipped") && stringp(weapon_type = inv[i]->query("skill_type")) )
		{
			weapon = new( "/clone/weapon/" + weapon_type );			
			weapon->set("value", 0);
			weapon->move( obj );			
			weapon->wield();
		}
	obj->set( "family_name", thief_master->query("family/family_name") );
	obj->set("title", obj->query("family_name") + "弟子");
	obj->set("name", obj->query("fname"));
 	destruct( thief_master );
	return obj;
}

// 開始論劍 人數少於2的 取消比賽
int start_competition()
{
        object env,room;
        object *obs;
        object npc;
        string proom;
        int i,j,user_num = 0;
        

	env = find_object(READY_ROOM);
        if (! objectp(env))
                return 0;
                
	obs = all_inventory(env);
	for (i=0;i<sizeof(obs);i++)
	{
		if ( userp (obs[i]) && !obs[i]->query_temp("noliving") 
			&& obs[i]->query_temp("bwdh_join") )
		user_num += 1;
	}		
	
  if ( user_num < 2)
  {
    for (i=0;i<sizeof(obs);i++)
    {
      obs[i]->move(ENTRY_ROOM);
      message("vision", HIG "本次華山論劍因爲參加英雄太少取消了！\n", obs[i]);
    }
    return 0;
  }
   	
  message("vision", "公平子向大家一揮手，說到：＂華山論劍現在開始！”\n", env);
      
  for (i = 0; i < sizeof(obs); i++)
  {
    if ( userp (obs[i])&& !obs[i]->query_temp("noliving") && obs[i]->query_temp("bwdh_join") )
		{
			for (j=0;j<2;j++)  // 一個player對應兩個npc
			{
			npc = create_thief( obs[i] );
			proom = sprintf(PK_ROOM "%d", random(12) + 1);
			if(!( room = find_object( proom )))
			room = load_object( proom );
			npc->move( room );
		  }
			tell_object(obs[i], HIY "你眼前忽然一花……\n" NOR);			
//      obs[i]->move(sprintf(PK_ROOM "%d", random(12) + 1));
      proom = sprintf(PK_ROOM "%d", random(12) + 1);
			if(!( room = find_object( proom )))
			room = load_object( proom );
			obs[i]->move( room );
      tell_object(obs[i], HIY "你定神一看，這才發現自己已經到了紫竹林。\n"NOR);
		}
  }

//        set_heart_beat(5);
        return user_num;
}

// 收集賽場內的最新情況
void auto_check()
{
   object room;
   object ob;
   object *obs;
   string *file;
   int i,j,user_num=0;
   string *u_name=({});
   string msg="";
                
   if (state != STARTING)                  	           	
     return;        
	
	file = get_dir(PK_DIR);       
  for ( i = 0 ; i <sizeof(file); i++)
  {
    if(!( room = find_object(PK_DIR + file[i]) ))
			  room = load_object(PK_DIR + file[i]);
		obs = all_inventory(room);
		for ( j = 0 ; j <sizeof(obs); j++)
		{        
       if ( userp(obs[j]) )
       {
         ob=obs[j];
         u_name += ({ obs[j]->query("name")+"("+obs[j]->query("id")+")" });
         user_num += 1;
       }
    }
  }    	                    	

  if ( user_num < 1)        
	{
		message("channel:snow", HIC"【謠言】"+"聽說華山頂上參加"+tlist[0]["name"][selected]+"的高手死的死，逃的逃，現在一個人都沒有啦！\n"NOR, users());
		kickout_players();
		change_state(SLEEPING);
	}
  else if ( user_num == 1)
  {
    message("channel:snow", HIC"【華山論劍】"+"公平子：本次"+tlist[0]["name"][selected]+"圓滿結束，" + ob->query("name") + "成爲第一高手！\n"NOR, users());                
    give_bouns(ob);
    change_state(SLEEPING);
    kickout_players();
  } 
  else  
  {
   for (i=0;i<user_num-1;i++)
  	msg += u_name[i] + "、";
   msg += u_name[user_num-1];
   message("channel:sys", HIC"【華山論劍】公平子：華山捨身崖上還有"+msg+"這"+chinese_number(user_num)+"名俠士，參加"+tlist[0]["name"][selected]+"。\n"NOR, users());
   return;      
  }
}

void give_bouns(object me)
{       
        int pot,exp,score;      
        
        tell_object(me, "這次你真是爽呆了……\n"); 
        me->move(ENTRY_ROOM);
        message_vision("$N興沖沖地走了出來，臉上掛滿是勝利的喜悅！\n",me);     
        pot = 500 + (int)me->query_temp("bwdh_pknum")*500+(int)me->query_temp("bwdh_nknum")*100+random(1000);
        exp = 1000 + (int)me->query_temp("bwdh_pknum")*1000+(int)me->query_temp("bwdh_nknum")*200+random(2000);
        score = 300 + (int)me->query_temp("bwdh_pknum")*300+(int)me->query_temp("bwdh_nknum")*60+random(800);

//        if ( (int)me->query_temp("bwdh_nknum") <= 2 )
        if ( !me->query_temp("bwdh_nknum")  )
        {
        	pot = pot/10;
        	exp = exp/10;
        }
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->add("score",score);
        me->delete_temp("bwdh_join");
        me->delete_temp("bwdh_pknum");
        me->delete_temp("bwdh_nknum");
	      me->remove_all_killer();
//        me->remove_all_enemy(1);
        me->remove_all_enemy();
        tell_object(me,HIW"你獲得本次比賽的最後勝利，得到如下獎勵：\n");
        tell_object(me,chinese_number(exp) +"點實戰經驗\n" +
        chinese_number(pot) + "點潛能。\n"+
        chinese_number(score) + "點江湖閱歷。\n"NOR);  
}

// 比賽開始前，對符合條件的玩家發出邀請
void send_invite_message()
{
        object *obs;
        int exp_ul, exp_dl,i;

	obs = users();
        exp_dl = tlist[0]["minexp"][selected];
        exp_ul = tlist[0]["maxexp"][selected];
        
        if (! sizeof(obs))
                return;
        
        for (i=0;i<sizeof(obs);i++)
        {
        	if ( obs[i]->query("combat_exp") >= exp_dl && obs[i]->query("combat_exp") <= exp_ul )
        	message("channel:snow", HIR "你收到了公平子撒下的武林盟帖，邀請你參加這次"+tlist[0]["name"][selected] + "！\n" NOR,obs[i]);
	}
}

//提供wiz手動開啓論劍
int start_by_others(int n)
{
        if (state == STARTING)
                return notify_fail("現在比賽正在進行中。\n");

        if (state == GET_READY)
                return notify_fail("現在比賽正在報名中。\n");

        if (n < 0 || n >= tlist[0]["lvl_num"])
                return notify_fail("沒有這個等級的比賽(0-" +
                                   (tlist[0]["lvl_num"] - 1) + ")。\n");
        selected = n;
        change_state(GET_READY);
        return 1;
}

// 判斷是否拒絕參加論劍
string reject_join(object me)
{
        int exp;

        if (state == STARTING)
                return "現在" + tlist[0]["name"][selected] + "正在舉行，你還是下次再來吧。";

        if (state != GET_READY)
                return "現在沒要舉行華山論劍啊？你跑來幹什麼？";

        exp = me->query("combat_exp");
        if (exp < tlist[0]["minexp"][selected])
                return "閣下還是先提高點經驗再來參加論劍吧。";

        if (exp > tlist[0]["maxexp"][selected])
                return "哦…您武功如此高強，這次還是別和小輩們爭了。";

        return 0;
}