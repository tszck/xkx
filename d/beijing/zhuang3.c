#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_break(string arg);
int do_climb(string arg);

void create()
{
	set("short", "莊府大門");
	set("long", @LONG
這裏就是文士莊允城的舊居。自從他被朝廷抓走後，這裏好象就沒
有人住了。一扇大門 (men)緊鎖着，周圍是高高的圍牆(wall)。一切都
很乾淨，並沒有積多少灰塵。
LONG );
	set("outdoors", "huabei");
	set("exits", ([
		"south" : __DIR__"zhuang2",
	]));
	set("item_desc", ([
		"men" : "這扇門是鎖着的，除非你打破(break)它。\n",
		"wall" : "牆很高，可能翻不過去(climb)。\n",
	]) );
	set("no_clean_up", 0);
	set("coor/x", 100);
	set("coor/y", 4700);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_break", "break");
	add_action("do_climb", "climb");
}

int do_break(string arg)
{
	int n;
	object me = this_player();

	n = me->query("neili");
	if( !arg || arg!="men" )
	{
		write("不要隨便打碎別人的東西！\n");
		return 1;
	}
	message_vision("$N走到門前，深吸一口氣，雙掌同時拍出。\n", me);
	if (n>=200)
	{
		message_vision("$N只聽一聲轟響，$N把門震開了！\n", me);
		set("exits/north", __DIR__"zhuang4");
		me->set("neili",n-200);
		remove_call_out("close");
		call_out("close", 5, this_object());
	}
	else
	{
		message_vision("$N大吼一聲“開！”，結果什麼也沒發生。看來$N的內力不夠強。\n", me);
		me->set("neili",0);
	}
	return 1;
}

int do_climb(string arg)
{
	int n;
	object me = this_player();

	n = me->query_skill("dodge");
	if( !arg || arg!="wall" )
	{
		write("不要到處亂爬！\n");
		return 1;
	}
	message_vision("$N在牆前站定，深吸一口氣，猛然躍起。\n", me);
	if (n>=80)
	{
		message_vision("只見$N足尖在牆上一點，已悠然飄落院中。\n", me);
		me->move(__DIR__"zhuang4");
	}
	else
		if (n>=50)
		{
			message_vision("只見$N雙手在牆上一攀，勉強翻過圍牆，跌落院中。\n", me);
			me->move(__DIR__"zhuang4");
		}
		else
		{
			message_vision("$N高高躍起，可還差一大截呢，看來是輕功不夠好。\n", me);
		}
		return 1;
}

void close(object room)
{
	message("vision","門吱呀一聲又合上了,好象有鬼。\n", room);
	room->delete("exits/north");
}
