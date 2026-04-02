// Room: /d/nanshaolin/fota2.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
#include <room.h>
inherit ROOM;
string look_wuse();
string look_wuxiang();
string look_kuzhi();
string look_kuhui();
string look_tianming();
string look_huizhi();
void create()
{
	set("short", "聖僧塔");
	set("long", @LONG
本層供奉着少林上代幾位有德高僧的靈體法臺，塔做六角之形，分
六個方位，六碑上字跡乃是無色臺(wuse)，無相牌 (wuxiang)，天鳴禪
臺(tianming), 苦智靈碑(kuzhi)，苦慧屏(kuhui)，晦智聖座(huizhi)。
   幾縷天光透過塔窗灑在塔內，似乎爲千年古塔增添了一點活力。
LONG );
	set("exits", ([
		"up"   : __DIR__"fota3",
		"down" : __DIR__"fota1",
	]));
	set("item_desc",([
		"wuse"     : (: look_wuse :),
		"wuxiang"  : (: look_wuxiang :),
		"tianming" : (: look_tianming :),
		"kuzhi"    : (: look_kuzhi :),
		"kuhui"    : (: look_kuhui :),
		"huizhi"   : (: look_huizhi :),
	]));
	set("no_clean_up", 0);
	set("coor/x", 1750);
	set("coor/y", -6190);
	set("coor/z", 20);
	setup();
}

void init()
{
	add_action("do_say", "say");
	add_action("do_sheshen","sheshen");
	add_action("do_fushi","fushi");
	add_action("do_chuzhang","chuzhang");
	add_action("do_chuzhang","break");
	add_action("do_shenru","shenru");
	add_action("do_taotuo","taotuo");
	add_action("do_canchan","canchan");
	add_action("do_canchan","buddhism");
	add_action("do_enter","enter");
}

int do_say(string arg)
{
	object me = this_player();
// string dir;
	if (arg=="今日大歡喜，舍卻危脆身")
	{
		write( "無色禪師的靈臺突然旋轉起來，發出隆隆聲響。一個聲音直透你心底，你甘願爲我佛捨身嗎？\n");
		me->set_temp("poem_said",1);
		return 1;
	}
	if (arg=="若得不馳散，深入實相不")
	{
		write("既有此心，何不實施？\n");
		me->set_temp("shen_said",1);
		return 1;
	}
	if (arg=="其心無所樂")
	{
		write("你心中難過，不由得垂下眼，瞑目靜思，冥冥中只要逃脫此地。\n");
		me->set_temp("m_said",1);
		return 1;
	}
}
int do_sheshen()
{
	object me = this_player();
	if(me->query_temp("poem_said"))
	{
		me->delete_temp("poem_said");
		if ((int)me->query_skill("buddhism",1)<30)
		{
			write("你雖有此心，奈何佛法修爲太差，反而傷到自己。\n");
			me->unconcious();
			return 1;
		}
		write( "你口中誦到：“無嗔亦無憂，寧不當欣慶？”身形直向法臺撞去，\n只聽“砰”的一聲，你已被送進了法臺。\n");
		me->move(__DIR__"wusetai");
		tell_room(environment(me),me->name()+"一頭撞了進來。\n",({me}));
		return 1;
	}
}
int do_canchan(string arg)
{
	object me = this_player();
	if (arg!="zuo" && arg!="聖座")
		return notify_fail("你要對什麼參悟禪理？\n");
	message("vision", me->name()+"對着大師的聖座冥思參禪。\n", environment(me), ({me}) );
	write("你在心中默默唸誦“仁者所得法，幸願示其要。”\n");
	if (random(3)==1)
	{
		write(HIR"你在虛空中，感覺大師座下打開了一個小門。\n" NOR);
		me->set_temp("marks/門",1);
		return 1;
	}
	return 1;
}

int do_enter()
{
	object me = this_player();
	if ((int)this_player()->query_temp("marks/門"))
	{
		me->delete_temp("marks/門");
		write("你連忙用手扶向小門。\n");
		if ((int)me->query_skill("hand",1)<30)
		{
			write(HIR"你手法太慢，小門已經消失，你頭腦中只覺一片昏亂。\n"NOR);
			me->unconcious();
			return 1;
		}
		message("vision", me->name()+"雙手亂舞，身形飄出，突然消失在聖座下了。\n", environment(me), ({me}) );
		write(HIR"你從小門中走了進去。\n"NOR);
		me->move(__DIR__"huizhizuo");
		tell_room(environment(me), me->name() + "跳了下來。\n", ({me}));
		return 1;
	}
	return 0;
}

int do_shenru()
{
	object me = this_player();
	if(me->query_temp("shen_said"))
	{
		me->delete_temp("shen_said");
		write("你身形一縱，十指如鉤，在禪臺邊上一抓要借力躍起。\n");
		message("vision", me->name()+"身形一縱，十指如鉤，在禪臺邊上一抓要借力縱起。\n", environment(me), ({me}) );
		if((int)me->query_skill("claw",1)<30)
		{
			write("你手指與臺邊差了寸許，沒有抓到。啊.....。\n");
			message("vision", me->name()+"手指與臺邊還有一定距離，沒有抓到。\n", environment(me), ({me}) );
			message("vision", me->name()+"一聲大叫，一個倒栽蔥摔將下來。\n", environment(me), ({me}) );
			me->unconcious();
			return 1;
		}
		write( "你在臺邊一借力，身子凌空直上，落在塔樑上，你腳下一滑，直摔向禪臺。\n");
		message("vision", me->name()+"凌空直上，落在塔樑上。突然向下一晃，便蹤跡皆無。\n", environment(me), ({me}) );
		me->move(__DIR__"tianming");
		tell_room(environment(me), me->name() + "摔了下來。\n", ({me}));
		return 1;
	}
	return 0;
}

int do_taotuo()
{
	object me = this_player();
	if (me->query_temp("m_said"))
	{
		me->delete_temp("m_said");
		message("vision", me->name()+"兩腿連環踢出，身形躍向塔窗便要逃出。\n", environment(me), ({me}) );
		if ((int)me->query_skill("leg",1)<30)
		{
			write("你兩腿已經麻木了，被定在當地。\n");
			return 1;
		}
		message("vision", me->name()+"身子一下消失在窗邊。\n", environment(me), ({me}) );
		write(HIR "你剛到窗邊，只覺眼前一黑，便跌將落去。\n"NOR);
		me->move(__DIR__"kuhuiping");
		tell_room(environment(me), me->name() + "跳了下來。\n", ({me}));
		return 1;
	}
	return 0;
}

int do_fushi(string arg)
{
	object me = this_player();
	if (arg!="pai"&&arg!="牌") return notify_fail("你要拂拭什麼？\n");
	message("vision", me->name()+"輕輕地在無相牌上拭去塵土。\n", environment(me), ({me}) );
	write("你輕輕地拂拭無相牌。\n");
	if (random(2)==1)
	{
		write(HIR"你突然有一種出掌的衝動，便想一掌擊出。\n"NOR);
		me->set_temp("marks/拍",1);
	}
	return 1;
}

int do_chuzhang(string arg)
{
	object me = this_player();
	if ((int)me->query_temp("marks/拍"))
	{
		if(arg!="pai" && arg!="牌")
			return notify_fail("你要哪出掌？\n");
		me->delete_temp("marks/拍");
		if ((int)me->query("neili",1)>100)
		{
			write(HIR"你氣運丹田，嘿的一聲向靈牌推出一掌。只聽啪的一聲，靈牌裂開一道大縫，你縱身向縫隙中跳去。\n"NOR);
			message("vision", me->name()+"氣運丹田，嘿的一聲向靈牌推出一掌。只聽啪的一聲，靈牌裂開一道大縫\n", environment(me), ({me}));
			message("vision", me->name()+"向縫隙直栽進去。一聲悶響，無相牌神奇的合好如初。\n" , environment(me), ({me}));
			me->receive_damage("neili",100);
			me->move(__DIR__"wuxiangpai");
			return 1;
		}
		message("vision", me->name()+"啪的推出一掌，但真氣不純，反而傷到自己\n", environment(me), ({me}));
		me->set("neili",0);
		return 1;
	}
	return 0;
}

string look_wuse()
{
	return "\n"
	"    ********************************************\n"
	"    ********************************************\n"
	"    ********　　　　　　　　　　　　　　********\n"
	"    ********　諸天無雲翳，四面皆清明。　********\n"
	"    ********　　　　　　　　　　　　　　********\n"
	"    ********　微風吹香氣，衆山寂無聲。　********\n"
	"    ********　　　　　　　　　　　　　　********\n"
	"    ********　今日大歡喜，舍卻危脆身。　********\n"
	"    ********　　　　　　　　　　　　　　********\n"
	"    ********　無嗔亦無憂，寧不當欣慶？　********\n"
	"    ********　　　　　　　　　　　　　　********\n"
	"    ********************************************\n"
	"    ********************************************\n";
}
string look_wuxiang()
{
	return "\n"
        "    ********************************\n"
	"    ********************************\n"
	"    ********　　　　　　　　********\n"
	"    ********　身若菩提樹，　********\n"
	"    ********　　　　　　　　********\n"
	"    ********　心如明鏡臺。  ********\n"
	"    ********　　　　　　　　********\n"
	"    ********　從今勤拂拭，　********\n"
	"    ********　　　　　　　　********\n"
	"    ********　不令惹塵埃。　********\n"
	"    ********　　　　　　　　********\n"
	"    ********************************\n"
	"    ********************************\n";
}
string look_tianming()
{
	return "\n"
        "    ********************************\n"
	"    ********************************\n"
	"    ********　　　　　　　　********\n"
	"    ********　既已舍染樂，　********\n"
	"    ********　　　　　　　　********\n"
	"    ********　心得善攝不？  ********\n"
	"    ********　　　　　　　　********\n"
	"    ********  若得不馳散，　********\n"
	"    ********　　　　　　　　********\n"
	"    ********　深入實相不？　********\n"
	"    ********　　　　　　　　********\n"
	"    ********************************\n"
	"    ********************************\n";
}
string look_kuhui()
{
	return "\n"
        "    ********************************\n"
	"    ********************************\n"
	"    ********　　　　　　　　********\n"
	"    ********  畢竟空相中，  ********\n"
	"    ********　　　　　　　　********\n"
	"    ********　其心無所樂？  ********\n"
	"    ********　　　　　　　　********\n"
	"    ********  若悅禪智慧，　********\n"
	"    ********　　　　　　　　********\n"
	"    ********　是法性無照。　********\n"
	"    ********　　　　　　　　********\n"
	"    ********************************\n"
	"    ********************************\n";
}
string look_huizhi()
{
	return "\n"
        "    ********************************\n"
	"    ********************************\n"
	"    ********　　　　　　　　********\n"
	"    ********  虛誑等無實，  ********\n"
	"    ********　　　　　　　　********\n"
	"    ********　亦非停心處。  ********\n"
	"    ********　　　　　　　　********\n"
	"    ********  仁者所得法，　********\n"
	"    ********　　　　　　　　********\n"
	"    ********　幸願示其要。　********\n"
	"    ********　　　　　　　　********\n"
	"    ********************************\n"
	"    ********************************\n";
}
string look_kuzhi()
{
	return "\n"
 	"    ********************************************\n"
	"    ********************************************\n"
	"    ********　　　　　　　　　　　　　　********\n"
	"    ********　一切恩愛會，皆由因緣合。　********\n"
	"    ********　　　　　　　　　　　　　　********\n"
	"    ********　會合有別離，無常難得久。　********\n"
	"    ********　　　　　　　　　　　　　　********\n"
	"    ********　今我爲爾母，恆恐不自保。　********\n"
	"    ********　　　　　　　　　　　　　　********\n"
	"    ********　生死多畏懼，命危於晨露。　********\n"
	"    ********　　　　　　　　　　　　　　********\n"
	"    ********************************************\n"
	"    ********************************************\n";
}
