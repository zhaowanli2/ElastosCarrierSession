package com.elastos.carrier.elastoscarriersession;

import android.graphics.Bitmap;
import android.graphics.Color;
import android.text.TextUtils;
import java.util.Hashtable;
import com.google.zxing.BarcodeFormat;
import com.google.zxing.EncodeHintType;
import com.google.zxing.WriterException;
import com.google.zxing.common.BitMatrix;
import com.google.zxing.qrcode.QRCodeWriter;

public class QRCodeUtils {
    public class Constant {
        public static final int REQ_QR_CODE = 11002; // // 打开扫描界面请求码
        public static final int REQ_PERM_CAMERA = 11003; // 打开摄像头

        public static final String INTENT_EXTRA_KEY_QR_SCAN = "qr_scan_result";
    }

    public static Bitmap createQRCodeBitmap(String content)
    {
//        return createQRCodeBitmap(content, 480, 480);
        return createQRCodeBitmap(content, 640, 640);
    }

    public static Bitmap createQRCodeBitmap(String content, int width, int height)
    {
        return createQRCodeBitmap(content, width, height, "UTF-8", "H", "2", Color.BLACK, Color.WHITE);
    }

    public static Bitmap createQRCodeBitmap(String content, int width, int height, String character_set, String error_correction, String margin, int color_black, int color_white)
    {
        if(TextUtils.isEmpty(content)) {
            return null;
        }

        if(width < 0 || height < 0){
            return null;
        }

        try {
            Hashtable<EncodeHintType, String> hints = new Hashtable<>();
            if(!TextUtils.isEmpty(character_set)) {
                hints.put(EncodeHintType.CHARACTER_SET, character_set);
            }

            if(!TextUtils.isEmpty(error_correction)) {
                hints.put(EncodeHintType.ERROR_CORRECTION, error_correction);
            }

            if(!TextUtils.isEmpty(margin)) {
                hints.put(EncodeHintType.MARGIN, margin);
            }

            BitMatrix bitMatrix = new QRCodeWriter().encode(content, BarcodeFormat.QR_CODE, width, height, hints);

            int[] pixels = new int[width * height];
            for(int y = 0; y < height; y++) {
                for(int x = 0; x < width; x++) {
                    if(bitMatrix.get(x, y)) {
                        pixels[y * width + x] = color_black;
                    }
                    else { pixels[y * width + x] = color_white;
                    }
                }
            }

            Bitmap bitmap = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888);
            bitmap.setPixels(pixels, 0, width, 0, 0, width, height);
            return bitmap;
        }
        catch (WriterException e) {
            e.printStackTrace();
        }

        return null;
    }
}
