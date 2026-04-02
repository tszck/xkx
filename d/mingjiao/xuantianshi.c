// Room: /d/mingjiao/xuantianshi.c


inherit ROOM;

void create()
{
	set("short", "懸天石");
	set("long", @LONG
從石上遠眺，只見雲海蒼茫處，險絕萬巒生，崑崙一脈，逶迤千里，
真一派大好江山。關於懸天石，還有許多傳説。相傳明教第三十代教主
〖風舞柳影〗阿娜(Doll)為解明教之難，捨身於此，明教一代絕學“乾
坤大挪移”從此失傳。許多後來之人於此憑弔，莫不泣淚，但更多的是
從此石跳下，想尋找“乾坤大挪移”祕籍，卻從沒有人能安然而歸。
LONG );
	set("exits", ([
		"down" : __DIR__"shanlu3",
	]));
	set("item_desc", ([
		"doll" : "一個來自波斯總教的教主。\n",
	]));
	set("outdoors", "mingjiao");
	set("coor/x", -52030);
	set("coor/y", 810);
	set("coor/z", 40);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
