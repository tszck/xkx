// natured.c
// Last Modified by Winder on Aug. 25 2001

#include <ansi.h>
// #define TIME_TICK ((time()-1270000000)*60)
//#define TIME_TICK ((time()-1111000000)*365)//現實一秒mud365秒
					   //現實一天mud365天(一年)
#define TIME_TICK ((time()%(60*24*3600))*365)//mud中60年一輪=現實中60天
nosave int current_day_phase;
mapping *day_phase;

//飛賊任務與隱士任務的標識
int thief_yinshi = 3;

string *weather_msg = ({
	"天空中萬裏無雲",
	"幾朵淡淡的雲彩妝點著清朗的天空",
	"白雲在天空中飄來飄去",
	"厚厚的雲層堆積在天邊",
	"天空中烏雲密佈",
});

mapping *read_table(string file);
void init_day_phase();

void create()
{
	day_phase = read_table("/adm/etc/nature/day_phase");
	init_day_phase();
}

void init_day_phase()
{
	mixed *local;
	int i, t;

	// Get minutes of today.
	local = localtime(TIME_TICK);
	t = local[2] * 60 + local[1];
	// hour * 60 + minutes

	// Find the day phase for now.
	for( i=0; i < sizeof(day_phase); i++)
		if( t >= day_phase[i]["length"] )
			t -= (int)day_phase[i]["length"];
		else break;

	current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);
	current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);
	// MUD 運行時間久了，時間會有偏差，這裏是調整程序，每小時執行一次
	message("channel:sys", HIR"【系統】泥巴時間對齊系統時間，一小時一次。\n"NOR, users());
	remove_call_out("init_day_phase");
	call_out("init_day_phase", 3600);

	// Since in our time scale, 1 minute == 1 second in RL, so we don't need
	// any conversion before using this number as call_out dalay, if you
	// changed the time scale, be sure to convert it.

	call_out("update_day_phase", (int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"]-t);
}

void update_day_phase()
{
	remove_call_out("update_day_phase");

	current_day_phase = (++current_day_phase) % sizeof(day_phase);
	message("outdoor:vision", HIG"【窗外】"NOR + day_phase[current_day_phase]["time_msg"] + NOR"。\n", users());
	if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
		call_other(this_object(), day_phase[current_day_phase]["event_fun"]);

	call_out("update_day_phase", day_phase[current_day_phase]["length"]);
}
void event_midnight()
{
	string get_month, get_day;
	get_day = CHINESE_D->chinese_monthday(TIME_TICK);
	get_month = CHINESE_D->chinese_month(TIME_TICK);
	switch(get_month)
	{
		//spring weather
		case "三":
		case "四":
		case "五":
			switch(random(3))
			{
			case 0:
				day_phase = read_table("/adm/etc/nature/spring_rain"); break;
			case 1:
				day_phase = read_table("/adm/etc/nature/spring_sun"); break;
			case 2:
				day_phase = read_table("/adm/etc/nature/spring_wind"); break;
			}
			break;
		//summer weather
		case "六":
		case "七":
		case "八":
			switch(random(3))
			{
			case 0:
				day_phase = read_table("/adm/etc/nature/summer_rain"); break;
			case 1:
				day_phase = read_table("/adm/etc/nature/summer_sun"); break;
			case 2:
				day_phase = read_table("/adm/etc/nature/summer_wind"); break;
			}
			break;
		//autumn weather
		case "九":
		case "十":
		case "十一":
			switch(random(3))
			{
			case 0:
				day_phase = read_table("/adm/etc/nature/autumn_rain"); break;
			case 1:
				day_phase = read_table("/adm/etc/nature/autumn_sun"); break;
			case 2:
				day_phase = read_table("/adm/etc/nature/autumn_wind"); break;
			}
			break;
		//winter weather
		case "十二":
		case "一":
		case "二":
			switch(random(3))
			{
			case 0:
				day_phase = read_table("/adm/etc/nature/winter_rain"); break;
			case 1:
				day_phase = read_table("/adm/etc/nature/winter_sun"); break;
			case 2:
				day_phase = read_table("/adm/etc/nature/winter_wind"); break;
			}
			break;
		default:
			day_phase = read_table("/adm/etc/nature/day_phase");
	}
}

object create_thief( )
{
	mapping skill_status,name;
	string *sname;	
	object obj;
	int skilllvl,topexp;
	int i;
	
	seteuid(getuid());
	if (thief_yinshi==0)	obj = new("/clone/quest/questfeizei");
	if (thief_yinshi==1)	obj = new("/clone/quest/questyinshi");
	if (random(2) == 0)
	{
	        if (thief_yinshi==1) name = NAME_D->woman_name();
		obj->set("gender", "女性");
	}
	else
	{
		if (thief_yinshi==1) name = NAME_D->man_name();
		obj->set("gender", "男性");
	}
        if (thief_yinshi==1) obj->set("fname", name["name"]);
/* skilllvl && exp for 飛賊 */    
     if (thief_yinshi==0)
        {
       	   i=random(5);
           if( i==0 )   
	       { topexp = 500000+random(500000);
                 skilllvl=100+random(50);
                 obj->set("str_lvl",1);
                } 
           else if( i==1 )   
	       { topexp = 1000000+random(1000000);
                 skilllvl=150+random(75);
                 obj->set("str_lvl",2);
                }          
           else if( i==2 )   
	       { topexp = 3000000+random(3000000);
                 skilllvl=200+random(100);
                 obj->set("str_lvl",3);
                }    
            else if( i==3 )   
	       { topexp = 5000000+random(5000000);
                 skilllvl=250+random(125);
                 obj->set("str_lvl",4);
                }  
             else if( i==4 )   
	       { topexp = 8000000+random(8000000);
                 skilllvl=300+random(150);
                 obj->set("str_lvl",5);
                }                        
         }
/* skilllvl && exp for 隱士*/
      if (thief_yinshi==1)
          { 
            skilllvl=250;
            topexp=3000000;            		
	   }          
            
      	obj->set("combat_exp", topexp); 
	NPC_D->copy_skill(obj);
 	if (mapp(skill_status = obj->query_skills()))
 	{
 		sname = keys(skill_status);
 		for(i=0;i<sizeof(skill_status);i++)
 		{
 			obj->set_skill(sname[i],skilllvl);
 		}
 	}
	return obj;
}
void event_morning()
{
 string *dir, *file;
	object yinshi;
	object room;
 int i,j;

        thief_yinshi=1;
        yinshi=create_thief();
//選擇地點
	dir = get_dir("/d/");
	i = random(sizeof(dir));
	file = get_dir("/d/"+dir[i]+"/");
	j = random(sizeof(file));
	if(  	file[j][<2..<1]!=".c" ||
		dir[i]=="death" ||
		dir[i]=="wizard" ||
		dir[i]=="working" ||
		dir[i]=="binghuo" ||
		dir[i]=="xiakedao" ||
		dir[i]=="npc" )
	     {
		    dir[i]="wuyi";
	    	    file[j]="sangufeng";
		    room = load_object("/d/wuyi/sangufeng");
	      }
   if(!objectp(room) && !( room = find_object("/d/"+dir[i]+"/"+file[j]) ))
		room = load_object("/d/"+dir[i]+"/"+file[j]);
	 if (room->query_max_encumbrance() < 10000000)
	 {
	 	dir[i]="wuyi";
	 	file[j]="sangufeng";
	  room = load_object("/d/wuyi/sangufeng");
	}
	yinshi->move(room);
	CHANNEL_D->do_channel(yinshi, "sys",yinshi->query("name")+"在"+room->query("short")+"(/d/"+dir[i]+"/"+file[j]+")。\n");	        				
        message("channel:snow", HIY"【江湖傳聞】"HIC + "聽說在"+ to_chinese(dir[i]) + "一帶隱居着一位武林前輩，江湖人士紛紛前往尋訪！\n"NOR,users() );
//還原標識
	thief_yinshi=3;              
}

void event_afternoon()
{       
	object *ob_list;
	int i;
	ob_list = children("/clone/quest/questyinshi");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
			message_vision("$N笑道：天要黑了，我也該走啦！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
}
	
void event_night()
{
	object badguy;
	object room;
	int num;
	num=random(15);
	thief_yinshi=0;
        if ( num == 0)
        {
		if(objectp(room=load_object("/d/city/shilijie4")))
		 badguy= create_thief();
		 badguy->move(room);
		message("channel:snow", HIM"【官府通告】"HIR + "揚州城中今夜有飛賊橫行，良民百姓請閉門不出，切莫自誤！\n"NOR,users() );
	}
        else if ( num == 1)
        {
		if(objectp(room=load_object("/d/beijing/tian_anm")))
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"【官府通告】"HIR + "北京城中今夜有飛賊橫行，良民百姓請閉門不出，切莫自誤！\n"NOR,users() );
	}
        else if ( num == 2)
        {
		if(objectp(room=load_object("/d/changan/center")))
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"【官府通告】"HIR + "長安城中今夜有飛賊橫行，良民百姓請閉門不出，切莫自誤！\n"NOR,users() );
	}
         else if ( num == 3)
        {
		if(objectp(room=load_object("/d/fuzhou/dongjiekou")))
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"【官府通告】"HIR + "福州城中今夜有飛賊橫行，良民百姓請閉門不出，切莫自誤！\n"NOR,users() );
	}
         else if ( num == 4)
        {
		if(objectp(room=load_object("/d/quanzhou/guangchang")) )
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"【官府通告】"HIR + "泉州城中今夜有飛賊橫行，良民百姓請閉門不出，切莫自誤！\n"NOR,users() );
	}
         else if ( num == 5)
        {
		if(objectp(room=load_object("/d/suzhou/baodaiqiao")) )
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"【官府通告】"HIR + "蘇州城中今夜有飛賊橫行，良民百姓請閉門不出，切莫自誤！\n"NOR,users() );
	}
         else if ( num == 6)
        {
		if(objectp(room=load_object("/d/hangzhou/jujingyuan")) )
		badguy= create_thief();
		badguy->move(room);		
		message("channel:snow", HIM"【官府通告】"HIR + "杭州城中今夜有飛賊橫行，良民百姓請閉門不出，切莫自誤！\n"NOR,users() );
	}
         else if ( num == 7)
        {
		if(objectp(room=load_object("/d/wuxi/guangchang")) )
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"【官府通告】"HIR + "無錫城中今夜有飛賊橫行，良民百姓請閉門不出，切莫自誤！\n"NOR,users() );
	}
        else if ( num == 8)
        {
		if(objectp(room=load_object("/d/xiangyang/guangchang")) )
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"【官府通告】"HIR + "襄陽城中今夜有飛賊橫行，良民百姓請閉門不出，切莫自誤！\n"NOR,users() );
	}
         else if ( num == 9)
        {
		if(objectp(room=load_object("/d/yueyang/zhongxin")) )
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"【官府通告】"HIR + "嶽陽城中今夜有飛賊橫行，良民百姓請閉門不出，切莫自誤！\n"NOR,users() );
	}
         else if ( num == 10)
        {
		if(objectp(room=load_object("/d/chengdu/guangchang")))
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"【官府通告】"HIR + "成都城中今夜有飛賊橫行，良民百姓請閉門不出，切莫自誤！\n"NOR,users() );
	}
         else if ( num == 11)
        {
		if(objectp(room=load_object("/d/dali/center")) )
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"【官府通告】"HIR + "大理城中今夜有飛賊橫行，良民百姓請閉門不出，切莫自誤！\n"NOR,users() );
        }
        else if ( num == 12)
        {
		if(objectp(room=load_object("/d/lingzhou/center")) )
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"【官府通告】"HIR + "靈州城中今夜有飛賊橫行，良民百姓請閉門不出，切莫自誤！\n"NOR,users() );
	}
       else if ( num == 13)
        {
		if(objectp(room=load_object("/d/foshan/street3")) )
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"【官府通告】"HIR + "佛山鎮中今夜有飛賊橫行，良民百姓請閉門不出，切莫自誤！\n"NOR,users() );
        }
       else 
        {
		if(objectp(room=load_object("/d/jiangling/xijie2")) )
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"【官府通告】"HIR + "江陵城中今夜有飛賊橫行，良民百姓請閉門不出，切莫自誤！\n"NOR,users() );
         }
//還原標識
       thief_yinshi=3;
}

void event_dawn()
{
	object *ob_list;
	int i;
	ob_list = children("/clone/quest/questfeizei");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
			message_vision("$N笑道：天亮了，東西也到手了，我閃！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
}
// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase

void event_noon()
{
	object *ob;
 int i,con,con1,con2,con3;
	string get_month,ill,msg;
	get_month = CHINESE_D->chinese_month(TIME_TICK);
	switch(get_month)
	{
		case "三":
		case "四":
		case "五":
			ill = "ill_kesou";
			msg = HIG"忽然喉頭一陣痕癢，你感覺似乎要咳嗽了。\n"NOR;
			break;
		case "六":
		case "七":
		case "八":
			ill = "ill_zhongshu";
			msg = HIG"突然你胸臆之間一陣翻騰，你中暑了。\n"NOR;
			break;
		case "九":
		case "十":
		case "十一":
			ill = "ill_shanghan";
			msg = HIG"陡的你打了個冷戰，頭昏沉沉的，你得傷寒病了。\n"NOR;
			break;
		case "十二":
		case "一":
		case "二":
			ill = "ill_dongshang";
			msg = HIG"你肢體末端一陣僵直，看來你被凍傷了。\n"NOR;
			break;
	}
	if(random(2))
	{
		ill = "ill_fashao";
		msg = HIG"你偶感風寒，竟而發起燒來。\n"NOR;
	}
	ob = users();
	for(i=0; i<sizeof(ob); i++)
	{
		if( !environment(ob[i]) ) continue;
		if( !environment(ob[i])->query("outdoors") ) continue;
		if( ob[i]->query("age")==14 ) continue;
		con1 = ob[i]->query("qi");
		con2 = ob[i]->query("max_qi");
		(int)con = con1/con2*50;//形成第一個生病判斷條件
		con3 = ob[i]->query("neili");
		con2 = ob[i]->query("max_neili");
		if( con2 == 0) con2 = 1;
		(int)con1 = con3/con2*50;//形成第二個生病判斷條件
		if(random(con)+random(50)+random(con1)<25)
		{
			ob[i]->apply_condition(ill, 10+random(40));
			tell_object(ob[i], msg);
		}
	}
}

string outdoor_room_description()
{
	return "    "+day_phase[current_day_phase]["desc_msg"]+NOR"。\n";
}
string outdoor_room_event()
{
	return day_phase[current_day_phase]["event_fun"];
}
string game_time()
{
	return CHINESE_D->chinese_date(TIME_TICK);
}

mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) ++rn;
	}
	return data;
}

mapping *query_day_phase() { return day_phase; }
