// mapd.c

// #pragma optimize
// #pragma save_binary

#include <ansi.h>

// 標識對應的地名
mapping map_short = ([
        "xiyu"      : "西域",
        "gaochang"  : "高昌附近",
        "xingxiu"   : "星宿海",
        "guanwai"   : "關外",
        "city"      : "揚州",
        "fuzhou"    : "福州",
        "xiangyang" : "襄陽",
        "suzhou"    : "蘇州",
        "hangzhou"  : "杭州",
        "quanzhou"  : "泉州",
        "lingzhou"  : "靈州",
        "chengdu"   : "成都",
        "jingzhou"  : "荊州",
        "jiaxing"   : "嘉興",
        "nanyang"   : "南陽",
        "foshan"    : "佛山",
        "dali"      : "大理",
        "changan"   : "長安",
        "wugong"    : "武功",
        "hengyang"  : "衡陽",
        "beijing"   : "北京",
        "shaolin"   : "少林",
        "wudang"    : "武當",
        "emei"      : "峨嵋",
        "qingcheng" : "青城",
        "mingjiao"  : "崑崙山",
        "quanzhen"  : "終南山",
        "henshan"   : "衡山",
        "taishan"   : "泰山",
        "huashan"   : "華山",
        "hengshan"  : "恆山",
        "songshan"  : "嵩山",
        "huanghe"   : "黃河",
        "lingjiu"   : "天山",
        "gumu"      : "古墓",
        "meizhuang" : "梅莊",
        "tianlongsi": "天龍寺",
        "xueshan"   : "雪山",
        "taohua"    : "桃花島",
        "baituo"    : "白駝山",
        "shenlong"  : "神龍島",
        "yanziwu"   : "燕子塢",
        "village"   : "華山村",
        "xiakedao"  : "俠客島",
        "xiaoyao"   : "逍遙林",
        "wanjiegu"  : "萬劫谷",
        "xuedao"    : "大雪山",
        "guiyun"    : "歸雲莊",
        "heimuya"   : "黑木崖",
        "motianya"  : "摩天崖",
        "nanhai"    : "南海之濱",
        "tiezhang"  : "鐵掌山",
        "kaifeng"   : "開封",
        "ruzhou"    : "汝州",
        "zhongzhou" : "中州",
        "luoyang"   : "洛陽",
        "lingxiao"  : "凌霄城",
        "lanzhou"   : "蘭州",
        "wudujiao"  : "五毒教",
        "honghua"   : "紅花會",
        "kunming"   : "昆明",
        "jueqing"   : "絕情谷",
]);

// 標識對應的地圖幫助文件(全部在HELP_DIR中)
mapping map_to = ([
        "xiyu"      : "map_xy",
        "gaochang"  : "map_xy",
        "xingxiu"   : "map_xxh",
        "guanwai"   : "map_gw",
        "city"      : "map_yz",
        "fuzhou"    : "map_fz",
        "xiangyang" : "map_xi",
        "suzhou"    : "map_sz",
        "hangzhou"  : "map_hz",
        "quanzhou"  : "map_qz",
        "lingzhou"  : "map_lz",
        "chengdu"   : "map_cd",
        "jingzhou"  : "map_jz",
        "jiaxing"   : "map_jx",
        "nanyang"   : "map_ny",
        "foshan"    : "map_fs",
        "dali"      : ({ "map_dl", "map_dls" }),
        "changan"   : "map_ca",
        "wugong"    : "map_wg",
        "hengyang"  : "map_hy",
        "beijing"   : "map_bj",
        "shaolin"   : "map_sl",
        "wudang"    : "map_wd",
        "emei"      : "map_em",
        "qingcheng" : "map_qc",
        "mingjiao"  : "map_kl",
        "quanzhen"  : ({ "map_zn", "map_cyg" }),
        "henshan"   : ({ "map_ss", "map_hy" }),
        "taishan"   : "map_es",
        "huashan"   : "map_ws",
        "hengshan"  : "map_ns",
        "songshan"  : "map_cs",
        "huanghe"   : "map_hh",
        "lingjiu"   : "map_ljg",
        "gumu"      : "map_gm",
        "meizhuang" : "map_mz",
        "tianlongsi": "map_tls",
        "xueshan"   : "map_xss",
        "taohua"    : "map_thd",
        "baituo"    : "map_bts",
        "shenlong"  : "map_sld",
        "yanziwu"   : "map_yzw",
        "village"   : "map_hsc",
        "xiakedao"  : "map_xkd",
        "xiaoyao"   : "map_xyl",
        "wanjiegu"  : "map_wjg",
        "xuedao"    : "map_xdm",
        "guiyun"    : "map_gyz",
        "heimuya"   : "map_hmy",
        "motianya"  : "map_mty",
        "nanhai"    : "map_nh",
        "tiezhang"  : "map_tz",
        "kaifeng"   : "map_kf",
        "ruzhou"    : "map_rz",
        "zhongzhou" : "map_zz",
        "luoyang"   : "map_ly",
        "lingxiao"  : "map_lxg",
        "lanzhou"   : "map_la",
        "wudujiao"  : ({ "map_wdj", "map_dls" }),
        "honghua"   : "map_hhh",
        "kunming"   : "map_km",
        "jueqing"   : "map_jqg",
]);

// 各地交通聯絡地
mapping map_trans = ([
        "beijing"   : ([ "name" : "北京",     "room" : "/d/beijing/majiu", ]),
        "yangzhou"  : ([ "name" : "揚州",     "room" : "/d/city/majiu", ]),
        "dali"      : ([ "name" : "大理",     "room" : "/d/dali/majiu", ]),
        "foshan"    : ([ "name" : "佛山",     "room" : "/d/foshan/majiu", ]),
        "fuzhou"    : ([ "name" : "福州",     "room" : "/d/fuzhou/majiu", ]),
        "guanwai"   : ([ "name" : "關外",     "room" : "/d/guanwai/majiu", ]),
        "hangzhou"  : ([ "name" : "杭州",     "room" : "/d/hangzhou/majiu", ]),
        "lanzhou"   : ([ "name" : "蘭州",     "room" : "/d/lanzhou/majiu", ]),
        "lingzhou"  : ([ "name" : "靈州",     "room" : "/d/lingzhou/majiu", ]),
        "luoyang"   : ([ "name" : "洛陽",     "room" : "/d/luoyang/majiu", ]),
        "yongdeng"  : ([ "name" : "永登",     "room" : "/d/huanghe/majiu", ]),
        "suzhou"    : ([ "name" : "蘇州",     "room" : "/d/suzhou/majiu", ]),
        "xiangyang" : ([ "name" : "襄陽",     "room" : "/d/xiangyang/majiu", ]),
        "yili"      : ([ "name" : "伊犁",     "room" : "/d/xingxiu/majiu", ]),
        "chengdu"   : ([ "name" : "成都",     "room" : "/d/city3/majiu", ]),
        "emei"      : ([ "name" : "峨嵋山",   "room" : "/d/emei/majiu1", ]),
        "emei2"     : ([ "name" : "峨嵋半山", "room" : "/d/emei/majiu2", ]),
        "quanzhou"  : ([ "name" : "泉州",     "room" : "/d/quanzhou/majiu1", ]),
        "jiaxing"   : ([ "name" : "嘉興",     "room" : "/d/quanzhou/majiu2", ]),
        "jingzhou"  : ([ "name" : "荊州",     "room" : "/d/jingzhou/majiu", ]),
        "nanyang"   : ([ "name" : "南陽",     "room" : "/d/shaolin/majiu1", ]),
        "changan"   : ([ "name" : "長安",     "room" : "/d/changan/majiu", ]),
        "wugong"    : ([ "name" : "武功鎮",   "room" : "/d/quanzhen/majiu", ]),
        "hengyang"  : ([ "name" : "衡陽",     "room" : "/d/henshan/majiu", ]),
        "kaifeng"   : ([ "name" : "開封",     "room" : "/d/kaifeng/majiu", ]),
        "kunming"   : ([ "name" : "昆明",     "room" : "/d/kunming/majiu", ]),
        "zhongzhou" : ([ "name" : "中州",     "room" : "/d/zhongzhou/majiu", ]),
]);


// 交通連接
mixed connect_info = ({
        ({ "beijing", "guanwai",        300, }),
        ({ "beijing", "lingzhou",       300, }),
        ({ "beijing", "changan",        200, }),
        ({ "beijing", "xiangyang",      180, }),
        ({ "beijing", "luoyang",        160, }),
        ({ "beijing", "nanyang",        150, }),
        ({ "beijing", "kaifeng",        160, }),
        ({ "beijing", "zhongzhou",      150, }),
        ({ "beijing", "yangzhou",       200, }),
        ({ "lingzhou", "yili",          250, }),
        ({ "lingzhou", "kaifeng",       180, }),
        ({ "lingzhou", "lanzhou",       120, }),
        ({ "lingzhou", "yongdeng",      100, }),
        ({ "lingzhou", "changan",       200, }),
        ({ "luoyang", "kaifeng",        140, }),
        ({ "luoyang", "changan",        100, }),
        ({ "luoyang", "yangzhou",       160, }),
        ({ "luoyang", "xiangyang",      100, }),
        ({ "luoyang", "zhongzhou",      120, }),
        ({ "luoyang", "wugong",          80, }),
        ({ "luoyang", "nanyang",        120, }),
        ({ "changan", "yili",           250, }),
        ({ "changan", "lanzhou",        100, }),
        ({ "changan", "wugong",          50, }),
        ({ "changan", "xiangyang",      200, }),
        ({ "changan", "nanyang",        200, }),
        ({ "changan", "kaifeng",        160, }),
        ({ "changan", "zhongzhou",      100, }),
        ({ "changan", "chengdu",        250, }),
        ({ "changan", "jingzhou",       230, }),
        ({ "changan", "yangzhou",       260, }),
        ({ "yangzhou", "nanyang",       100, }),
        ({ "yangzhou", "kaifeng",       120, }),
        ({ "yangzhou", "xiangyang",     150, }),
        ({ "yangzhou", "hengyang",      250, }),
        ({ "yangzhou", "suzhou",         80, }),
        ({ "yangzhou", "zhongzhou",      80, }),
        ({ "yangzhou", "hangzhou",      120, }),
        ({ "yangzhou", "jiaxing",       150, }),
        ({ "nanyang", "kaifeng",         50, }),
        ({ "nanyang", "zhongzhou",      120, }),
        ({ "xiangyang", "chengdu",      200, }),
        ({ "xiangyang", "jingzhou",      80, }),
        ({ "xiangyang", "dali",         400, }),
        ({ "xiangyang", "kunming",      500, }),
        ({ "xiangyang", "hengyang",     200, }),
        ({ "xiangyang", "zhongzhou",     80, }),
        ({ "chengdu", "jingzhou",       140, }),
        ({ "chengdu", "kunming",        220, }),
        ({ "chengdu", "emei",           150, }),
        ({ "chengdu", "dali",           300, }),
        ({ "dali",  "jingzhou",         180, }),
        ({ "dali",  "kunming",          150, }),
        ({ "emei",  "kunming",          120, }),
        ({ "emei",  "jingzhou",         140, }),
        ({ "emei",  "emei2",             20, }),
        ({ "hengyang", "foshan",        150, }),
        ({ "suzhou", "hangzhou",         80, }),
        ({ "suzhou", "jiaxing",         120, }),
        ({ "suzhou", "quanzhou",        150, }),
        ({ "suzhou", "zhongzhou",        80, }),
        ({ "hangzhou", "jiaxing",        50, }),
        ({ "hangzhou", "quanzhou",      150, }),
        ({ "hangzhou", "fuzhou",        140, }),
        ({ "lanzhou", "yongdeng",       100, }),
        ({ "lanzhou", "yili",           160, }),
        ({ "jiaxing", "fuzhou",         130, }),
        ({ "jingzhou", "kunming",       140, }),
        ({ "fuzhou", "quanzhou",         30, }),
        ({ "kaifeng", "yongdeng",       110, }),
        ({ "kaifeng", "zhongzhou",      100, }),
});

// 查看某個地點是否被MAPD所知曉
public int been_known(string outdoors)
{
        return stringp(map_short[outdoors]);
}

// 獲得某個戶外地點的中文名字
public string query_map_short(string outdoors)
{
        string str;

        if (stringp(str = map_short[outdoors]))
                return str;

        return "不詳地點";
}

// 獲得所有戶外地點的集合
public string *query_all_map_zone()
{
        return keys(map_short);
}

// 獲得某個戶外地點的地圖
public string query_maps(string outdoors)
{
        mixed maps;
        string file, map_result;
	int i;

        if (undefinedp(maps = map_to[outdoors]))
                return "未有詳細地圖。\n";

        if (stringp(maps))
        {
                file = HELP_DIR + maps;
                map_result = read_file(file);
                if (! stringp(map_result))
                        map_result = "無法讀取地圖" + file + "。\n";
                map_result = SHOP_D->color_filter(map_result);
                return map_result;
        }

        if (arrayp(maps))
        {
                map_result = "";
/* 替代 foreach */
		for ( i = 0; i < sizeof(maps); i++)
		{
			if (file == maps[i])
                	{
				if (file_size(HELP_DIR + file) > 0)
					map_result += read_file(HELP_DIR+file);
				else map_result += "無法讀取地圖"+file + "。\n";
			}
                }
/*
                foreach (file in maps)
                {
                        if (file_size(HELP_DIR + file) > 0)
                                map_result += read_file(HELP_DIR + file);
                        else
                                map_result += "無法讀取地圖" + file + "。\n";
                }
*/
                map_result = SHOP_D->color_filter(map_result);
                return map_result;
        }

        error("未知錯誤。\n");
}

// 獲得地圖中某一行的第x開始的n個字符，其中地圖行中@打頭的字
// 符及後續字符一概認為不佔地方。比如"@B123@E"，則第二個字符
// 是'2'，而不是B。如果n為-1，則返回一直到末尾的所有字符
//
// 這樣存在問題，有必要引入一個變量， 標識是否取回顏色，不過
// 由於出錯的幾率相當小，所以姑且不計。
string get_map_line(string line, int x, int n)
{
        string rs;

        rs = "";
        if (n == 0)
                return rs;

        // 找到相應的位置
        while (x)
        {
                if (strwidth(line) == 0)
                        // 字符串長度不夠
                        return rs;

                if (line[0] == '@')
                {
                        if (strwidth(line) >= 2)
                                // 去掉@和後續的字符
                                line = line[2..<1];
                        else
                                // 長度不夠？返回空字符串
                                return rs;
                } else
                {
                        // 字符串去掉第一個字符，相當於向右移動
                        x--;
                        line = line[1..<1];
                }
        }

        // 截取n個字符
        // 為什麼這裏用do-while，而不直接用while？這是有原因
        // 的。
        rs = "";
        for (;;)
        {
                if (strwidth(line) == 0)
                        // 已經無字符可取
                        return rs;

                if (line[0] == '@')
                {
                        if (strwidth(line) >= 2)
                        {
                                rs += line[0..1];
                                line = line[2..<1];
                        } else
                        {
                                rs += line;
                                return rs;
                        }
                } else
                {
                        if (n == 0) break; // 結束截取
                        n--;
                        rs += line[0..0];
                        line = line[1..<1];
                        continue;
                }
        }
        return rs;
}

// 為地點標記顏色：名字必須為中文
// 標記的時候一行行掃描，掃描的同時打標記，將標記設置為@B和
// @E，如果掃描成功就把@B和@E替換成為@R和@N，否則就去掉這些
// 臨時標記。
// 最後將將所有的標記替換成顏色：@R->WHT @N->NOR
public string mark_map(string map, string name)
{
        string *lines;
        string temp;
        string rs;
        int i;
        int x, y, xd;           // 比較的地圖位置
        int n;

        // 去除地圖的顏色：這樣可以準確的判斷絕對的座標
        map = SHOP_D->filter_color(map);

        // 將地圖分成行
        lines = explode(map, "\n");
        for (i = 0; i < sizeof(lines); i++)
        {
                if (strsrch(lines[i], name[0..1]) == -1)
                        // 本行不存在名稱的第一個漢字，繼續，繼續下一行
                        continue;

                x = 0;
                temp = replace_string(lines[i], "@R", "");
                temp = replace_string(temp, "@N", "");
                while (x < strwidth(temp) - 1)
                {
                        xd = strsrch(temp[x..<1], name[0..1]);
                        if (xd == -1)
                                // 本行後續沒有名稱的第一個漢字，繼續下一行
                                break;

                        // 該行匹配上了第一個漢字：比較後續的漢字，
                        // 首先橫向比較，因此不斷移動xd，如果橫向掃
                        // 描不到，就往縱向比較，變化y。
                        x += xd;
                        y = i;
                        xd = 2;
                        rs = get_map_line(lines[y], 0, x);
                        rs += "@B";
                        rs += get_map_line(lines[y], x, 2);
                        for (n = 2; n < strwidth(name); n += 2, xd += 2)
                        {
                                // 首先橫向比較
                                if (x + xd + 2 <= strwidth(lines[y]) &&
                                    get_map_line(lines[y], x + xd, 2) == name[n..n + 1])
                                {
                                        // 橫向比較到了，繼續橫向比較
                                        rs += name[n..n + 1];
                                        continue;
                                }

                                // 橫向比較失敗了，橫向還原對齊，縱向比較
                                rs += "@E" + get_map_line(lines[y], x + xd, -1);
                                xd = 0;
                                y++;
                                if (y < sizeof(lines) &&
                                    x + 2 <= strwidth(lines[y]) &&
                                    get_map_line(lines[y], x, 2) == name[n..n + 1])
                                {
                                        // 縱向比較到了，繼續橫向比較
                                        lines[y - 1] = rs;
                                        rs = get_map_line(lines[y], 0, x);
                                        rs += "@B";
                                        rs += name[n..n + 1];
                                        continue;
                                }

                                // 比較失敗，不在(x, i)這個位置
                                y--;
                                while (y >= i)
                                {
                                        // 恢復原先的地圖，去掉標記
                                        lines[y] = replace_string(lines[y], "@B", "");
                                        lines[y] = replace_string(lines[y], "@E", "");
                                        y--;
                                }
                                break;
                        }

                        if (n >= strwidth(name))
                        {
                                // 匹配成功
                                rs += "@E" + get_map_line(lines[y], x + xd, -1);
                                lines[y] = rs;
                                while (y >= i)
                                {
                                        // 將標記設置為正常標記
                                        lines[y] = replace_string(lines[y], "@B", "@R");
                                        lines[y] = replace_string(lines[y], "@E", "@N");
                                        y--;
                                }
                        }

                        // 移動x，繼續匹配
                        x++;
                }
                // 掃描完畢一行，繼續掃描下一行
        }
        // 處理完畢

        return implode(lines, "\n") + "\n";
}

// 獲得所在某個地點的地圖並標記當前所在的位置
public string marked_map(object env)
{
        mixed maps;
        string file, outdoors, map_result;
        int result_ok, i;

        if (! objectp(env))
                return "這裏無法獲得地圖。\n";

        if (! stringp(outdoors = env->query("outdoors")))
                return "必須在室外察看所處的具體位置。\n";

        if (undefinedp(maps = map_to[outdoors]))
                return "未有詳細地圖。\n";

        if (stringp(maps))
        {
                file = HELP_DIR + maps;
                map_result = read_file(file);
                if (! stringp(map_result))
                        map_result = "無法讀取地圖" + file + "。\n";
                map_result = SHOP_D->color_filter(map_result);
                map_result = mark_map(map_result, env->short());
        } else
        if (arrayp(maps))
        {
                map_result = "";
                result_ok = 0;
/* 替代 foreach */
		for ( i = 0; i < sizeof(maps); i++)
		{
			if (file == maps[i])
			{
				if (file_size(HELP_DIR + file) > 0)
					map_result = read_file(HELP_DIR + file);
				else
				{
					map_result = "無法讀取地圖"+file+"。\n";
					result_ok = 1;
					break;
				}

				map_result = SHOP_D->color_filter(map_result);
				map_result = mark_map(map_result, env->short());
				if (strsrch(map_result, "@R") != -1)
				{
					result_ok = 1;
					break;
				}
			}
		}
/*
                foreach (file in maps)
                {
                        if (file_size(HELP_DIR + file) > 0)
                                map_result = read_file(HELP_DIR + file);
                        else
                        {
                                map_result = "無法讀取地圖" + file + "。\n";
                                result_ok = 1;
                                break;
                        }

                        map_result = SHOP_D->color_filter(map_result);
                        map_result = mark_map(map_result, env->short());
                        if (strsrch(map_result, "@R") != -1)
                        {
                                result_ok = 1;
                                break;
                        }
                }
*/
                // 所有的地圖都沒有變化？取第一個
                if (! result_ok)
                {
                        map_result = read_file(HELP_DIR + maps[0]);
                        map_result = SHOP_D->color_filter(map_result);
                }
        } else
                error("未知錯誤。\n");

        map_result = replace_string(map_result, "@R", HIC);
        map_result = replace_string(map_result, "@N", NOR);
        return map_result;
}

// 玩家紀錄傳聞
public int record_rumor(mixed obs, string topic, mixed event_ob)
{
        
        string title;
        int n;

        if (objectp(obs)) obs = ({ obs }); else
        if (! arrayp(obs)) return 0;

        if (! stringp(title = event_ob->query_detail(topic)))
                return 0;

        if (stringp(event_ob)) event_ob = base_name(find_object(event_ob));
        else event_ob = base_name(event_ob);
        n = 0;
/*
        foreach (ob in obs)
        {
                if (! playerp(ob) || ! ob->query("out_family")) continue;
                if (ob->query("rumor/" + topic)) continue;
                ob->set("rumor/" + topic, event_ob);
                message("vision", "你掏出地圖冊，翻到最後面，寫下了有關『" +
                                  topic + "』的記錄。\n", ob);
                n++;
        }
*/
        return n;
}

// 獲得某個交通地點的信息
public varargs mixed query_trans_info(string to)
{
        if (! stringp(to))
                return map_trans;

        return map_trans[to];
}

// 獲得交通連接信息
public mapping query_connect_info()
{
        return connect_info;
}