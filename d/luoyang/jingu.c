// Room: /d/luoyang/jingu.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "金谷春晴");
	set("long",  @LONG
這裏就是當年金谷洞內的金谷園。是西晉鉅富石崇的別墅。他因與
貴族大地主王愷爭富，修築了金谷別墅，即稱“金谷園”。陽春三月，
風和日暖的時候，桃花灼灼、柳絲嫋嫋，樓閣亭樹交輝掩映，蝴蝶翩躍
飛舞於花間；小鳥啁啾，對語枝頭。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south" : __DIR__"tongtuo",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -370);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
