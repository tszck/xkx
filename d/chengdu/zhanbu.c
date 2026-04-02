// Room: /d/chengdu/zhanpu.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "占卜鋪");
	set("long", @LONG
門口掛着一塊招牌(sign)，裏面顯得有些空空蕩蕩的，瞎眼先生坐
在一張黑漆的方桌後，桌上鋪者一張白布，上面擺着一筒算命用的竹籤
和幾枚銅錢。方桌前有一張供客人坐的凳子。
LONG	);
	set("exits", ([
		"south" : __DIR__"xijie1",
	]));
	set("item_desc",([
		 "sign": "人算不如天算，天算不如我算。\n",
	]));
	set("no_clean_up", 0);
       	set("coor/x", -8070);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

