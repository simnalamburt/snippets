macro_rules! define {
    { $($key:tt = $value:expr;)+ } => {
        $(
            macro_rules! $key (() => ($value));
        )+
    }
}

define! {
    ACCESS_SYSTEM_SECURITY = 16777216;
    APPCMD_MASK = 4080;
    ACL_REVISION = 2;
    APPLICATION_ERROR_MASK = 536870912;
    ACL_REVISION1 = 1;
    ARABIC_CHARSET = 178;
    ACL_REVISION2 = 2;
    ASPECT_FILTERING = 1;
    AclRevisionInformation = 1;
    ASPECTX = 40;
    AclSizeInformation = 2;
    ASPECTXY = 44;
    AD_CLOCKWISE = 2;
    ASPECTY = 42;
    AD_COUNTERCLOCKWISE = 1;
    ASYNCH = 128;
    ALTERNATE = 1;
    ATTR_CONVERTED = 2;
    ANSI_CHARSET = 0;
    ATTR_INPUT = 0;
    ANSI_FIXED_FONT = 11;
    ATTR_INPUT_ERROR = 4;
    ANSI_VAR_FONT = 12;
    ATTR_TARGET_CONVERTED = 1;
    ANYSIZE_ARRAY = 1;
    ATTR_TARGET_NOTCONVERTED = 3;
    APPCLASS_MASK = 15;
    AUX_MAPPER = -1;
    APPCLASS_MONITOR = 1;
    AUXCAPS_AUXIN = 2;
    APPCLASS_STANDARD = 0;
    AUXCAPS_CDAUDIO = 1;
    APPCMD_CLIENTONLY = 16;
    AUXCAPS_LRVOLUME = 2;
    APPCMD_FILTERINITS = 32;
    AUXCAPS_VOLUME = 1;
    BACKGROUND_BLUE = 16;
}

fn main() {
    println!("{}", ACCESS_SYSTEM_SECURITY!());
}
