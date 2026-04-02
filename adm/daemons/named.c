// named.c 隨機姓名
//-----nm1與id是一一對應的，改動時要注意
//'司'、'寇'、'南'、'宮'是姓，'司寇'、'南宮'居然也是姓，pfpf呀~~
string* nm1 = ({
"趙","錢","孫","李","周","吳","鄭","王","馮","陳","褚","衞",
"蔣","沈","韓","楊","朱","秦","尤","許","何","呂","施","張",
"孔","曹","嚴","華","金","魏","陶","姜","戚","謝","鄒","喻",
"柏","水","竇","章","雲","蘇","潘","葛","奚","範","彭","郎",
"魯","韋","昌","馬","苗","鳳","花","方","俞","任","袁","柳",
"酆","鮑","史","唐","費","廉","岑","薛","雷","賀","倪","湯",
"藤","殷","羅","畢","郝","鄔","安","常","樂","於","時","傅",
"皮","卞","齊","康","伍","餘","元","卜","顧","盈","平","黃",
"和","穆","蕭","尹","姚","邵","湛","汪","祁","毛","禹","狄",
"米","貝","明","臧","計","伏","成","戴","談","宋","茅","龐",
"熊","紀","舒","屈","項","祝","董","梁","杜","阮","藍","閔",
"席","季","麻","強","賈","路","婁","危","江","童","顏","郭",
"梅","盛","林","刁","鍾","徐","邱","駱","高","夏","蔡","田",
"樊","胡","凌","霍","虞","萬","支","柯","咎","管","盧","莫",
"經","房","裘","繆","幹","解","應","宗","宣","丁","賁","鄧",
"鬱","單","杭","洪","包","諸","左","石","崔","吉","鈕","龔",
"万俟","司馬","上官","歐陽","夏候","諸葛","聞人","東方",
"赫連","皇甫","尉遲","公羊","澹臺","公治","宗政","濮陽",
"淳于","單於","太叔","申屠","公孫","仲孫","轅軒","令狐",
"鍾離","宇文","長孫","慕容","鮮於","閭丘","司徒","司空",
"亓","官","司","寇","仉","督","子","車","顓孫","端木","巫馬","公西",
"漆雕","樂正","壤駟","公良","拓拔","夾谷","宰父","穀梁",
"楚晉","閆法","汝鄢","塗欽","段幹","百里","東郭","南門",
"呼延","歸海","羊舌","微生","嶽","帥","緱","亢","況","後","有","琴",
"梁丘","左丘","東門","西門","商","牟","佘","佴","柏","賞","南","宮",
"墨","哈","譙","笪","年","愛","陽","佟","第","五","言","福",
});

string* id = ({
"zhao","qian","sun","li","zhou","wu","zheng","wang","feng","chen","chu","wei",
"jiang","shen","han","yang","zhu","qin","you","xu","he","lv","shi","zhang",
"kong","cao","yan","hua","jin","wei","tao","jiang","qi","xie","zou","yu",
"bai","shui","dou","zhang","yun","su","pan","ge","xi","fan","peng","lang",
"lu","wei","chang","ma","miao","feng","hua","fang","yu","ren","yuan","liu",
"feng","bao","shi","tang","fei","lian","cen","xue","lei","he","ni","tang",
"teng","yin","luo","bi","hao","wu","an","chang","yue","yu","shi","fu",
"pi","bian","qi","kang","wu","yu","yuan","bu","gu","ying","ping","huang",
"he","mu","xiao","yin","yao","shao","zhan","wang","qi","mao","yu","di",
"mi","bei","ming","zang","ji","fu","cheng","dai","tan","song","mao","pang",
"xiong","ji","shu","qu","xiang","zhu","dong","liang","du","ruan","lan","min",
"xi","ji","ma","qiang","jia","lu","lou","wei","jiang","tong","yan","guo",
"mei","sheng","lin","diao","zhong","xu","qiu","luo","gao","xia","cai","tian",
"fan","hu","ling","huo","yu","wan","zhi","ke","jiu","guan","lu","mo",
"jing","fang","qiu","miao","gan","xie","ying","zong","xuan","ding","ban","deng",
"yu","shan","hang","hong","bao","zhu","zuo","shi","cui","ji","niu","gong",
"moqi","sima","shangguan","ouyang","xiahou","zhuge","wenren","dongfang",
"helian","huangfu","yuchi","gongyang","dantai","gongye","zongzheng","puyang",
"chunyu","chanyu","taishu","shentu","gongsun","zhongsun","xuanyuan","linghu",
"zhongli","yuwen","zhangsun","murong","xianyu","lvqiu","situ","sikong",
"qi","guan","si","kou","zhang","du","zi","che","zhuansun","duanmu","wuma","gongxi",
"qidiao","yuezheng","xiangsi","gongliang","tuoba","jiagu","zaifu","guliang",
"chujin","yanfa","ruyan","tuqin","duangan","baili","dongguo","nanmen",
"huyan","guihai","yangshe","weisheng","yue","shuai","gou","kang","kuang","hou","you","qin",
"liangqiu","zuoqiu","dongmen","ximen","shang","mou","she","nai","bai","shang","nan","gong",
"mo","ha","qiao","da","nian","ai","yang","tong","di","wu","yan","fu",
});

//----nm2需要一定的空字，以便產生出單名--------------
string* nm2 = ({
"忠","孝","禮","義","智","勇","仁","匡","憲","令","福","祿","大","小","曉",
"高","可","阿","金","世","克","叔","之","公","夫","時","若","慶","文","武",
"多","才","長","子","永","友","自","人","為","鐵","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm3 = ({
"霸","白","班","斌","賓","昌","超","誠","川","鼎","定","鬥",
"法","飛","風","鋒","鋼","罡","貫","光","海","虎","華",
"浩","宏","濟","堅","健","劍","江","進","傑","俊","康",
"良","麟","民","明","鳴","寧","培","啓","強","榮","山",
"泰","濤","挺","偉","熙","祥","雄","旭",
"毅","瑜","羽","宇","嶽","舟",
});

string* nm4 = ({	  //女性專用
"愛","春","丹","芳","芬","鳳","姑","紅","虹","嬌","娟",
"菊","蘭","嵐","麗","莉","蓮","玲","琳","娜","琴","芹",
"倩","萍","婷","霞","香","豔","燕","英","瑛","玉","珍",
"珠",
});

//-日本名-----nm_jp與id_jp是一一對應的，改動或增加也要注意對應----------------
string *nm1_jp =({
"山本","龜田","姿三","大島","松下","橫田","東芝","候本","川野","山口",
"鈴木","崗倉","小島","井上","安奈","淺田","佐藤","廣末","大竹","大村",
"伯佐","富岡","東鄉",
});

string *id_jp =({
"shanben","guitian","zisan","dadao","songxia","hengtian","dongzhi","houben","chuanye","shankou",
"lingmu","gangcang","xiaodao","jinshang","annai","qiantian","zuoteng","guangmo","dazhu","dacun",
"bozuo","fugang","dongxiang",
});

string *nm2_jp =({
"太郎","次郎","三郎","四郎","五郎","十一郎","十四郎","二十六","俊樹",
"寧次","英機","冶字","俊雄","牧夫","光夫","敬一","英世","漱石","渝吉",
"一葉","子規","稻造","伊衝","松園","深水","大觀","豐國","孝和","茂",
"川","衞","島壽","光雲","安治","山樂","夢二",
});


mapping man_name()
{
	mapping name;
	int i;
	i = random(sizeof(nm1));
	name = ([
		"name" : nm1[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))],
		"id"   : id[i],
	]);
	return name;
}

mapping woman_name()
{
	mapping name;
	int i;
	i = random(sizeof(nm1));
	name = ([
		"name" : nm1[i]+nm2[random(sizeof(nm2))]+nm4[random(sizeof(nm4))],
		"id"   : id[i],
	]);
	return name;
}

mapping jap_name()
{
	mapping name;
	int i;
	i = random(sizeof(nm1_jp));
	name = ([
		"name" : nm1_jp[i]+nm2_jp[random(sizeof(nm2_jp))],
		"id"   : id_jp[i],
	]);
	return name;
}

mapping cn_sname = ([
        "阿" : "a",
        "艾" : "ai",
        "白" : "bai",
        "蔡" : "cai",
        "曹" : "cao",
        "陳" : "chen",
        "戴" : "dai",
        "竇" : "dou",
        "鄧" : "deng",
        "狄" : "di",
        "杜" : "du",
        "段" : "duan",
        "範" : "fan",
        "樊" : "fan",
        "房" : "fang",
        "風" : "feng",
        "符" : "fu",
        "福" : "fu",
        "高" : "gao",
        "古" : "gu",
        "關" : "guan",
        "郭" : "guo",
        "毛" : "mao",
        "韓" : "han",
        "胡" : "hu",
        "花" : "hua",
        "洪" : "hong",
        "侯" : "hou",
        "黃" : "huang",
        "賈" : "jia",
        "蔣" : "jiang",
        "金" : "jin",
        "孔" : "kong",
        "匡" : "kuang",
        "廖" : "liao",
        "梁" : "liang",
        "李" : "li",
        "林" : "lin",
        "劉" : "liu",
        "龍" : "long",
        "陸" : "lu",
        "盧" : "lu",
        "羅" : "luo",
        "馬" : "ma",
        "牛" : "niu",
        "龐" : "pang",
        "裴" : "pei",
        "彭" : "peng",
        "戚" : "qi",
        "齊" : "qi",
        "錢" : "qian",
        "喬" : "qiao",
        "秦" : "qin",
        "邱" : "qiu",
        "裘" : "qiu",
        "仇" : "qiu",
        "沙" : "sha",
        "商" : "shang",
        "尚" : "shang",
        "邵" : "shao",
        "沈" : "shen",
        "師" : "shi",
        "施" : "shi",
        "宋" : "song",
        "孫" : "sun",
        "童" : "tong",
        "萬" : "wan",
        "王" : "wang",
        "魏" : "wei",
        "衞" : "wei",
        "吳" : "wu",
        "武" : "wu",
        "蕭" : "xiao",
        "肖" : "xiao",
        "項" : "xiang",
        "許" : "xu",
        "徐" : "xu",
        "薛" : "xue",
        "楊" : "yang",
        "羊" : "yang",
        "陽" : "yang",
        "易" : "yi",
        "尹" : "yin",
        "俞" : "yu",
        "趙" : "zhao",
        "鍾" : "zhong",
        "周" : "zhou",
        "鄭" : "zheng",
        "朱" : "zhu",

        "東方" : "dongfang",
        "獨孤" : "dugu",
        "慕容" : "murong",
        "歐陽" : "ouyang",
        "司馬" : "sima",
        "西門" : "ximen",
        "尉遲" : "yuchi",
        "長孫" : "zhangsun",
        "諸葛" : "zhuge",
        "上官" : "shangguan",
        "夏侯" : "xiahou",
        "聞人" : "wenren",
        "皇甫" : "huangfu",
        "澹臺" : "tantai",
        "公治" : "gongzhi",
        "淳于" : "chunyu",
        "申屠" : "shentu",
        "公孫" : "gongsun",
        "公羊" : "gongyang",
        "軒轅" : "xuanyuan",
        "令狐" : "linghu",
        "鍾離" : "zhongli",
        "宇文" : "yuwen",
        "慕容" : "murong",
        "仲孫" : "zhongsun",
        "司徒" : "situ",
        "司空" : "sikong",
        "端木" : "duanmu",
        "公良" : "gongliang",
        "百里" : "baili",
        "東郭" : "dongguo",
        "鮮於" : "xianyu",
        "南郭" : "nanguo",
        "呼延" : "huyan",
        "羊舌" : "yangshe",
        "東門" : "dongmen",
        "納蘭" : "nalan",
        "南官" : "nanguan",
        "南宮" : "nangong",
        "拓拔" : "tuoba",
        "完顏" : "wanyan",
        "耶律" : "yelv",
]);

mapping cn_pname = ([
        "ai"   : "皚哀藹隘埃璦嬡捱",
        "an"   : "安黯諳岸鞍埯鵪",
        "ao"   : "奧傲敖驁翱鰲",
        "ang"  : "昂盎骯",
        "ba"   : "罷霸跋魃",
        "bai"  : "白佰",
        "ban"  : "斑般",
        "bang" : "邦",
        "bei"  : "北倍貝備",
        "biao" : "表標彪飈飆",
        "bian" : "邊卞弁忭",
        "bu"   : "步不",
        "cao"  : "曹草操漕",
        "cang" : "蒼倉",
        "chang": "常長昌敞瑒",
        "chi"  : "遲持池赤尺馳熾",
        "ci"   : "此次詞茨辭慈",
        "du"   : "獨都",
        "dong" : "東侗",
        "dou"  : "都篼",
        "fa"   : "發乏琺",
        "fan"  : "範凡反泛帆蕃",
        "fang" : "方訪邡昉",
        "feng" : "風鳳封豐奉楓峯鋒",
        "fu"   : "夫符弗芙",
        "gao"  : "高皋郜鎬",
        "hong" : "洪紅宏鴻虹泓弘",
        "hu"   : "虎忽湖護乎祜滸怙",
        "hua"  : "化花華驊樺",
        "hao"  : "號浩皓蒿浩昊灝淏",
        "ji"   : "積極濟技擊疾及基集記紀季繼吉計冀祭際籍績忌寂霽稷璣芨"
                 "薊戢佶奇詰笈畿犄",
        "jian" : "漸劍見建間柬堅儉",
        "kan"  : "刊戡龕",
        "ke"   : "可克科刻珂恪溘牁",
        "lang" : "朗浪廊琅閬莨",
        "li"   : "歷離裏理利立力麗禮黎慄荔瀝櫟璃",
        "lin"  : "臨霖林琳",
        "ma"   : "馬獁",
        "mao"  : "貿冒貌冒懋矛卯瑁",
        "miao" : "淼渺邈",
        "nan"  : "楠南腩赧",
        "pian" : "片翩胼",
        "qian" : "潛謙倩茜乾虔千",
        "qiang": "強羌錆瑲",
        "qin"  : "親琴欽沁芩矜",
        "qing" : "清慶卿晴",
        "ran"  : "冉然染燃",
        "ren"  : "仁刃壬仞",
        "sha"  : "沙煞",
        "shang": "上裳商",
        "shen" : "深審神申慎參莘",
        "shi"  : "師史石時十世士詩始示適炻",
        "shui" : "水",
        "si"   : "思斯絲司祀嗣巳",
        "song" : "松頌誦",
        "tang" : "堂唐棠瑭",
        "tong" : "統通同童彤仝",
        "tian" : "天田忝",
        "wan"  : "萬宛晚",
        "wei"  : "衞微偉維威韋緯煒惟瑋為",
        "wu"   : "吳物務武午五巫鄔兀毋戊",
        "xi"   : "西席錫洗夕兮熹惜",
        "xiao" : "瀟蕭笑曉肖霄驍校",
        "xiong": "熊雄",
        "yang" : "羊洋陽漾央秧煬颺鴦",
        "yi"   : "易意依亦伊夷倚毅義宜儀藝譯翼逸憶怡熠沂頤奕弈懿翊軼屹猗翌",
        "yin"  : "隱因引銀音寅吟胤誾煙蔭",
        "ying" : "映英影穎瑛應瑩郢鷹",
        "you"  : "幽悠右憂猷酉",
        "yu"   : "漁鬱寓於餘玉雨語預羽輿育宇禹域譽瑜嶼御渝毓虞禺豫裕鈺煜聿",
        "zhi"  : "制至值知質致智志直治執止置芝旨峙芷摯郅炙雉幟",
        "zhong": "中忠鍾衷",
        "zhou" : "周州舟胄繇晝",
        "zhu"  : "竹主駐朱祝諸珠著竺",
        "zhuo" : "卓灼灼拙琢濯斫擢焯酌",
        "zi"   : "子資茲紫姿孜梓秭",
        "zong" : "宗樅",
        "zu"   : "足族祖卒",
        "zuo"  : "作左佐笮鑿",
]);

void generate_cn_name(object ob)
{
        string sname, pname, pname2, id1, id2;
        string *ks, *kp;

        ks = keys(cn_sname);
        kp = keys(cn_pname);
        sname = ks[random(sizeof(ks))];
        for (;;)
        {
                pname = kp[random(sizeof(kp))];
                if (pname != cn_sname[sname]) break;
        }
        id1 = cn_sname[sname];

        id2 = pname;
        pname = cn_pname[pname];
        pname = pname[(random(sizeof(pname)) & 0xFFFE)..<1];
        pname = pname[0..0];
        if (random(3) == 0)
        {
                for (;;)
                {
                        pname2 = kp[random(sizeof(kp))];
                        if (pname2 != cn_sname[sname] &&
                            pname2 != pname) break;
                }
                id2 += pname2;
                pname2 = cn_pname[pname2];
                pname2 = pname2[(random(sizeof(pname2)) & 0xFFFE)..<1];
                pname2 = pname2[0..0];
        } else
                pname2 = "";

        if (ob) ob->set_name(sname + pname + pname2,
                             ({ id1 + " " + id2, id1, id2 }));
}
