// Room: /d/baituo/midao0.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIR"祕道"NOR);
	set("long", @LONG
這條陰暗的祕道在山腹中曲折延伸，不知通往何處。這裏有有一塊
大石柱(shizhu)擋着向上的出口，往前走好象可以看見一點亮光。
LONG);
	set("item_desc",([
		"shizhu" : "這是根巨型圓柱，看樣子應該可以扳(move)動她。\n",
	]));
	set("exits", ([
		"west" : __DIR__"midao1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -49920);
	set("coor/y", 20080);
	set("coor/z", 10);
	setup(); 
}

void init()
{
	add_action("do_move","move");
}

int do_move(string arg)
{
 
	object room;
	if( !arg || arg!="shizhu" ) return 0;
	message("vision","石柱忽然發出軋軋的聲音，向一側緩緩移開，向上露出一個光亮的出口。\n", this_object() );
	set("exits/up", __DIR__"yuanzi4");
	if( room = load_object(__DIR__"yuanzi4") )
	{
		room->set("exits/down", __FILE__);
		message("vision","石柱忽然發出軋軋的聲音，露出一個黑洞洞的洞口。\n",room );
	} 
	remove_call_out("close_door");
	call_out("close_door", 3);
	return 1;
}

void close_door()
{
	object room;
	if( !query("exits/up") ) return;
	message("vision","頭頂上忽然發出軋軋的聲音，石柱又緩緩地收了回去，階梯消失了。\n", this_object() );
	if( room = load_object(__DIR__"yuanzi4") )
	{
		room->delete("exits/down");
		message("vision","石柱忽然發出軋軋的聲音，緩緩地移回原處，將向下的洞口蓋住了。\n", room );
	}
	delete("exits/up");
}