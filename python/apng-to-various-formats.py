from re import match
from os import stat

# rm -f *.{webp,webm,avif}

# ffmpeg -i orig.png -c:v libwebp_anim -loop 0 -lossless 1 lossless.webp
# ffmpeg -i orig.png -c:v libwebp_anim -loop 0 -q:v 95 q95.webp
# ffmpeg -i orig.png -c:v libwebp_anim -loop 0 -q:v 90 q90.webp
# ffmpeg -i orig.png -c:v libwebp_anim -loop 0 -q:v 85 q85.webp
# ffmpeg -i orig.png -c:v libwebp_anim -loop 0 -q:v 75 q75.webp
# ffmpeg -i orig.png -c:v libwebp_anim -loop 0 -q:v 50 q50.webp

# ffmpeg -i orig.png -c:v libvpx-vp9 -lossless 1 lossless.webm
# ffmpeg -i orig.png -c:v libvpx-vp9 default.webm
# ffmpeg -i orig.png -c:v libvpx-vp9 -pass 1 -b:v 1000K -threads 1 -speed 4 -tile-columns 0 -frame-parallel 0 -g 9999 -aq-mode 0 -an -f webm /dev/null
# ffmpeg -i orig.png -c:v libvpx-vp9 -pass 2 -b:v 1000K -threads 1 -speed 0 -tile-columns 0 -frame-parallel 0 -auto-alt-ref 1 -lag-in-frames 25 -g 9999 -aq-mode 0 -f webm best.webm

# ffmpeg -i orig.png -strict -1 -pix_fmt yuva444p -f yuv4mpegpipe - | avifenc --stdin default.avif
# ffmpeg -i orig.png -strict -1 -pix_fmt yuva444p -f yuv4mpegpipe - | avifenc --stdin --min 32 --minalpha 32 q32.avif
# ffmpeg -i orig.png -strict -1 -pix_fmt yuva444p -f yuv4mpegpipe - | avifenc --stdin -a end-usage=q -a cq-level=32 cq32.avif
# ffmpeg -i orig.png -strict -1 -pix_fmt yuva444p -f yuv4mpegpipe - | avifenc --stdin -a end-usage=q -a cq-level=48 cq48.avif
# ffmpeg -i orig.png -strict -1 -pix_fmt yuva444p -f yuv4mpegpipe - | avifenc --stdin -a end-usage=q -a cq-level=52 cq52.avif
# ffmpeg -i orig.png -strict -1 -pix_fmt yuva444p -f yuv4mpegpipe - | avifenc --stdin -a end-usage=q -a cq-level=56 cq56.avif
# ffmpeg -i orig.png -strict -1 -pix_fmt yuva444p -f yuv4mpegpipe - | avifenc --stdin -a end-usage=q -a cq-level=60 cq60.avif
# ffmpeg -i orig.png -strict -1 -pix_fmt yuva444p -f yuv4mpegpipe - | avifenc --stdin -a end-usage=q -a cq-level=62 cq62.avif
# ffmpeg -i orig.png -strict -1 -pix_fmt yuva444p -f yuv4mpegpipe - | avifenc --stdin -a end-usage=q -a cq-level=63 cq63.avif

def generate_table(fmt):
    names, ext = match(r'\{((?:\w+,)*\w+)\}\.(\w+)', fmt).groups()
    names = names.split(',')
    is_image = ext in ('png', 'webp', 'heic', 'avif')

    def detail(name):
        path = f'{name}.{ext}'
        tag = f'<img src="{path}">' if is_image else f'<video autoplay muted loop><source src="{path}"></video>'

        size = stat(path).st_size
        kib = size / 1024
        mib = kib / 1024
        percent = size / 1314914 * 100
        return (f'''<td>
            {tag}
            <div>
                <span>{percent:.2f}%</span>
                <small>{size} B<br>{kib:.2f} KiB<br>{mib:.2f} MiB</small>
            </div>
        </td>''')

    return (
        '<table><tr>' +
        ''.join(f'<th>{name}</td>' for name in names) +
        '</tr><tr>' +
        ''.join(detail(name) for name in names) +
        '</tr></table>'
    )

print('''
<!doctype html>
<meta charset="UTF-8">

<style>
body {
  font-family: sans-serif;
  padding: 3rem;
  max-width: 900px;
  margin: 0 auto;
}
body[data-theme=dark] {
  background: #333;
  color: white;
}

label {
  position: fixed;
  left: 0.5rem;
  top: 0.75rem;
  padding: 0.25rem 0.7rem 0.25rem 0.5rem;
  background: rgba(255, 255, 255, 0.5);
  border-radius: 1rem;
}
body[data-theme=dark] label { background: rgba(0, 0, 0, 0.5); }

h2, hr { margin-top: 3rem; }

img { width: 256px; height: 256px; }

table { border-collapse: collapse; }
th { padding: 0.5rem; }
th, td { border: 0.5px solid #ddd; }
td > div {
  display: grid;
  padding: 0.25rem;
  grid: '. .';
  align-items: center;
}
td > div > small {
  text-align: right;
  font-size: 0.5rem;
}
body[data-theme=dark] th, body[data-theme=dark] td { border-color: #555; }
</style>

<label>
  <input type=checkbox id=checkbox>
  다크모드
</label>

<h2>.png image (APNG)</h2>
''' + generate_table('{original}.png') + '''
<h2>.webp iamge (VP8)</h2>
''' + generate_table('{lossless,q95,q90}.webp') + generate_table('{q85,q75,q50}.webp') + '''
<h2>.webm video (VP9)</h2>
''' + generate_table('{lossless,best,default}.webm') + '''
<h2>.heic image (HEIF, HEVC = H.265)</h2>
NOTE: 웹에선 표시 안되지만 네이티브 앱에선 표시시킬 수 있음
''' + generate_table('{default}.heic') + '''
<h2>avif image (AV1)</h2>
''' + generate_table('{default,q32,cq32}.avif') + generate_table('{cq48,cq52,cq56}.avif') + generate_table('{cq60,cq62,cq63}.avif') + '''
<hr>
NOTE: H.264는 알파채널을 지원 안해서 못씀
<script type=module>
if (matchMedia('(prefers-color-scheme: dark)').matches) { checkbox.checked = true }
const sync = _ => document.body.dataset.theme = checkbox.checked ? 'dark' : 'light'
checkbox.addEventListener('change', sync)
sync()
</script>
''')
