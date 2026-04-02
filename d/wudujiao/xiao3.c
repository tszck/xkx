// Room: /d/wudujiao/xiao3.c

inherit ROOM;

void create()
{
        set("short", "江邊小路");
        set("long", @LONG
這裏是桃花江邊的一條泥土小路，一旁就是清澈的江水。夾岸
連綿不斷的桃花燦若雲霞，暗香襲人，引來許多蜜蜂在花樹間飛舞。
前面有一個木牌(pai)立在路中央,由於風吹日曬，字跡已經模糊了。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "southeast" : __DIR__"taohua",
                "northwest" : __DIR__"xiao2",
        ]));
        set("item_desc",([
              "pai": " 前方桃花峪......,.....瘴氣.....危險。本村之人....闖入。\n村長  苗三斤 \n",
        ]));

	set("coor/x", -44990);
	set("coor/y", -81040);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}