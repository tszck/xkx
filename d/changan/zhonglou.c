// /d/changan/zhonglou.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "鐘樓");
	set  ("long",  @LONG
鐘樓建於明洪武一十三年。青條石爲方基，巨木爲塔樓。樓內懸掛
巨鍾一口，用以報時，鐘樓因此得名。樓前是個熱鬧的廣場，西南可以
看到天下聞名的碑林，西北和鐘樓遙相呼應。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"down"  :  __DIR__"center",
	]));
	set("outdoors",  "changan");
	set("coor/x", -5040);
	set("coor/y", 1000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
