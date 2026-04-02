// Room: /d/lingxiao/yuan.c 淵側 
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short", "分天淵側");
	set("long", @LONG
過了分天崖，回頭望望，白雲寥寥，雲氣瀰漫，想想還有點後怕，
但畢竟過來了。往前看，就是凌霄城了，這座武林中傳説的名城，終於
出現在你面前了，趕快進去看看吧。
LONG);
	set("outdoors", "lingxiao");
	set("exits", ([
		"up"   : __DIR__"shanya",
		"down" : __DIR__"bingti",
	]));
	set("coor/x", -31000);
	set("coor/y", -8940);
	set("coor/z", 135);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


