// /d/meizhuang/keting.c
// Last Modified by winder on Apr. 10 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "迎客亭"); 
	set("long", @LONG
通過四雅清風，你來到了梅莊的迎客亭，這裏雖然只有一張石桌几
個石凳，但卻是一塵不染，石凳和石桌之間的空隙很大，顯是方便來客
與主人相互寒暄。一位漢子正站在亭前，衝你拱手微笑。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"dating",
		"north" : __DIR__"senlin1",
	]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/shi" : 1,
	]));
	set("no_clean_up", 0);
	set("item_desc", ([
		"table": "一張很平常的石桌，但是......自己猜吧。\n"
	]) );

	set("coor/x", 3500);
	set("coor/y", -1410);
	set("coor/z", 10);
	setup();
}
void init()
{
	add_action("do_zuan", "zuan");
}
int do_zuan(string arg)
{
 
	object me=this_player();

	if( !arg || arg=="" )
	{
		write("你要往哪兒鑽？\n");return 1;
	}
	if( arg=="table" )
	{
		write("你躡手躡腳的繞到石桌的後面，鑽進了下面的一個小洞。\n");
		if((int)me->query_skill("dodge",1)>=30)
		{
			write( "你費盡九牛二虎之力，發現自己到了一個很神祕的地道里。\n");
			me->move(__DIR__"didao1");
			return 1;
		}
		write(RED"你試着鑽了一下後面的一個小洞，發現鑽不進去。\n"NOR);
		me->add("jing",-10);
		me->add("qi",-10);

		return 1;
	}
}