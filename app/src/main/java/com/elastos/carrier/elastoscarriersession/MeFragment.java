package com.elastos.carrier.elastoscarriersession;

import android.graphics.Bitmap;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;

public class MeFragment extends Fragment {
	private View mMain;
	private ImageView mQrcode = null;
	private String mAddress = null;
	private int mQrcWidth = 0;

	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container,
			Bundle savedInstanceState) {
		mMain = inflater.inflate(R.layout.fragment_me, container, false);
		mQrcode = (ImageView) mMain.findViewById(R.id.myaddressqrcode);
		return mMain;
	}

    public void showQRCode(String address) {
		if (mQrcode != null && address != null && !address.isEmpty() && mQrcWidth > 0) {
            Bitmap mBitmap = QRCodeUtils.createQRCodeBitmap(address, mQrcWidth, mQrcWidth);
            mQrcode.setImageBitmap(mBitmap);
        }
	}

	public void setAddress(String address, int width) {
		mAddress = address;
		mQrcWidth = width;
        showQRCode(mAddress);
	}

	@Override
	public void onStart() {
		super.onStart();

		showQRCode(mAddress);
	}
}
