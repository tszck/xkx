// /d/wizard/guest_room.c

#include <room.h>
inherit ROOM;

int is_chat_room() { return 1; }

void create()
{
	set("short", "巫師會客室");
	set("long", @LONG
這裏是巫師和玩家交流的地方，如果你有什麼問題需要向巫師請
教，可以在這裏留言(post)。不過如果問題牽涉到解謎或者已經在幫
助文件裏有詳細說明，巫師們就不一定會回答。樓上是巫師休息室，
一般玩家到這裏後就上不去了。西邊是新建的BUG留言室，如果有發現
什麼bug，或者想看看處理的結果，都可以過去逛逛。
LONG );

	set("exits", ([
		"up": __DIR__"wizard_room",
		"southeast": "/d/city/wumiao",
		"west" : __DIR__"bug_room",
        ]));
	set("item_desc", ([
		"up": "不要偷窺。\n",	
        ]));
//  set("objects", ([
//      "/clone/npc/qingyun" : 1,
//  ]));
	set("no_fight", "1");
	set("no_clean_up", 0);
	create_door("southeast", "竹門", "northwest", DOOR_CLOSED);
	setup();
	call_other("/clone/board/towiz_b", "???");
	"/clone/npc/qingyun"->move(this_object());
}

int valid_leave(object me, string dir)
{
        if( dir=="up" && !wizardp(me) )
                return notify_fail("那裏只有巫師才能進去。\n");
        return ::valid_leave(me, dir);
}

