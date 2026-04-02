// /d/meizhuang/jianyu.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", BLU"梅莊地牢"NOR);
	set("long", @LONG
這裏黑黑暗暗，幾乎伸手不見五指。唯一的光亮來自牆上忽明忽暗
的松油燈。地上和牆上佈滿了暗紅色的血痕，散發出陣陣腥氣。不斷傳
來的喘息聲在死沉的地牢裏迴盪，令人毛骨聳然。從地牢的牆縫裏透出
幾縷陽光。西邊是一扇緊閉的囚門。
LONG
	);
	set("item_desc", ([
		"door" : "囚門似乎以前有人動過什麼手腳。\n",
		"門"   : "囚門似乎以前有人動過什麼手腳。\n",
	]) );
	set("objects", ([
		CLASS_D("heimuya")+"/ren" : 1,
	]) );
	set("valid_startroom","1");

	set("coor/x", 3510);
	set("coor/y", -1420);
	set("coor/z", -10);
	setup();
}

void init()
{
	add_action("do_push", "push");
}

void check_trigger()
{
	object room;
	if( (int)query("trigger")==8 && !query("exits/out") )
	{
		message("vision","囚室門被你推得裂開了一道縫隙，剛好可以容你鑽出去。\n", this_object() );
		set("exits/west", __DIR__"midao4");
		if(!( room = find_object(__DIR__"midao4")) )
			room = load_object(__DIR__"midao4");
		message("vision", "囚室門突然裂開一條窄縫。\n", room );
		room->set("exits/east", __FILE__);
		delete("trigger");
		call_out("close_passage", 5);
	}
}

void close_passage()
{
	object room;

	if( !query("exits/west") ) return;
	message("vision","鐵門伊咿呀呀一陣響，砰地一聲又關上了。\n", this_object());
	if( room = find_object(__DIR__"midao4") )
	{
		message("vision", "鐵門伊咿呀呀一陣響，砰地一聲又關上了。\n", room);
		room->delete("exits/east");
	}
	delete("exits/west");
}

int do_push(string arg)
{
 

	if( !arg || arg=="" )
	{
		write("你要推什麼？\n");
		return 1;
	}

	if( arg=="door" || arg == "門")
	{
		add("trigger", 1);
		write("你試着用力推着緊閉着的囚門，似乎有一點鬆動....\n");
		check_trigger();
		return 1;
	}
}

void reset()
{
	::reset();
	delete("trigger");
}
