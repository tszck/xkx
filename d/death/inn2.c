// This is a room made by roommaker.
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "黑店");
	set("long", YEL @LONG
屋裏相當冷清，外面的濃霧還不時地從半開著的門縫飄進來，地面
上散著一些破舊的物品，不過光從外表已經無法分辨出那是些什麼東西
了。牆上(wall)刻著一些潦草的字體，牆角的一盞燈籠掙扎似地發出一
陣陣微弱的光芒，也使得那些字看來格外的詭異。
LONG NOR);
        set("no_fight", 1);
        set("exits", ([
		"west" : __DIR__"difu2",
	]) );
	set("item_desc", ([
		"wall" : @WALL
幾行你勉強分辨得出來的字：
我被困在這裏了.... 我要回家啦！！！！！！！！
		      ^^^^
                        靠自己啦...
什麼叫靠自己啊？！？！？！這裏連個活人都沒有...

看到你自己時問一下吧... 自己人都會互相幫忙的説.. 
				    ^^^^
                                 你... 確... 定？！？！
喔.. 
WALL
	]) );
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
